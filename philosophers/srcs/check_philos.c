/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:45:37 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/29 20:29:49 by kyuminkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died_philo(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].last_eat_mutex);
		if (get_time() - philo[i].last_eat > args->time_to_die)
		{
			pthread_mutex_lock(&args->finished_mutex);
			args->finished = 1;
			pthread_mutex_unlock(&args->finished_mutex);
			checker_print(args, i, "died");
			pthread_mutex_unlock(&philo[i].last_eat_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo[i].last_eat_mutex);
		usleep(50);
		i++;
	}
	return (0);
}

int	check_end_philo(t_args *args)
{
	pthread_mutex_lock(&args->end_philo_mutex);
	if ((args->num_of_must_eat != 0)
		&& (args->num_of_philo == args->end_philo))
	{
		pthread_mutex_lock(&args->finished_mutex);
		args->finished = 1;
		pthread_mutex_unlock(&args->finished_mutex);
		pthread_mutex_unlock(&args->end_philo_mutex);
		return (1);
	}
	pthread_mutex_unlock(&args->end_philo_mutex);
	return (0);
}

void	check_finished(t_args *args, t_philo *philo)
{
	int	i;

	while (!args->finished)
	{
		if (args->num_of_must_eat != 0)
		{
			i = check_end_philo(args);
			if (i)
				break ;
		}
		if (check_died_philo(args, philo))
			break ;
	}
}

int	check_finished_routine(t_philo *philo)
{
	if (philo->finished)
		return (1);
	pthread_mutex_lock(&philo->args->finished_mutex);
	if (philo->args->finished)
	{
		pthread_mutex_unlock(&philo->args->finished_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->finished_mutex);
	return (0);
}
