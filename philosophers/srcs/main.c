/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:02:51 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/23 21:21:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		print_error("Error: Invalid arguments\n");
	}
	init_args(&args, argc, argv);
	init_mutex(&args);
	init_philo(&args, &philo);
	start_philo(&args, philo);
	free_philo(&args, philo);
}

void	start_philo(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	args->start_time = get_time();
	while (i < args->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			print_error("Error: Failed to create thread\n");
		i++;
	}
	check_finished(args, philo, 0);
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			print_error("Error: Failed to join thread\n");
		i++;
	}
}

void	check_finished(t_args *args, t_philo *philo, int i)
{
	while (!args->finished)
	{
		if ((args->num_of_must_eat != 0)
			&& (args->num_of_philo == args->end_philo))
		{
			args->finished = 1;
			checker_print(args, "All philosophers have eaten enough");
			break ;
		}
		while (i < args->num_of_philo)
		{
			pthread_mutex_lock(&philo[i].last_eat_mutex);
			if (get_time() - philo[i].last_eat > args->time_to_die)
			{
				pthread_mutex_lock(&args->finished_mutex);
				checker_print(args, "A philosopher died");
				args->finished = 1;
				pthread_mutex_unlock(&args->finished_mutex);
				pthread_mutex_unlock(&philo[i].last_eat_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo[i].last_eat_mutex);
			i++;
		}
	}
}

void	*routine(void *philo)
{
	t_philo	*cur_philo;

	cur_philo = (t_philo *)philo;
	while (1)
	{
		if (check_finished_routine(cur_philo))
			break ;
		if (cur_philo->id % 2 == 0)
			usleep(100);
		if (check_finished_routine(cur_philo))
			break ;
		else
			philo_think(cur_philo);
		if (check_finished_routine(cur_philo))
			break ;
		else
			philo_eat(cur_philo);
		if (cur_philo->finished)
			break ;
		if (check_finished_routine(cur_philo))
			break ;
		else
			philo_sleep(cur_philo);
	}
	return (0);
}

int	check_finished_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->finished_mutex);
	if (philo->args->finished)
	{
		pthread_mutex_unlock(&philo->args->finished_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->finished_mutex);
	return (0);
}
