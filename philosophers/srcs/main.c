/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:02:51 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/27 01:36:29 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (print_error("Error: Invalid arguments\n"));
	if (init_args(&args, argc, argv) == -1)
		return (print_error("Error: Failed to initialize arguments\n"));
	if (init_mutex(&args) == -1)
		return (print_error("Error: Failed to initialize mutex\n"));
	if (init_philo(&args, &philo) == -1)
		return (print_error("Error: Failed to initialize philosophers\n"));
	if (start_philo(&args, philo) == 1)
		return (print_error("Error: Failed to start philosophers\n"));
	if (free_philo(&args, philo, 0) != 0)
		return (print_error("Error: Failed to free philosophers\n"));
	return (0);
}

int	start_philo(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&args->start_mutex);
	while (i < args->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (1);
		i++;
	}
	args->start_time = get_time();
	pthread_mutex_unlock(&args->start_mutex);
	check_finished(args, philo);
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
