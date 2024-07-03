/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:14:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/03 14:08:09 by kyuminkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_args *args, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * args->num_of_philo);
	if (!*philo)
		return (-1);
	i = 0;
	while (i < args->num_of_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].finished = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % args->num_of_philo;
		(*philo)[i].eat_count = 0;
		(*philo)[i].last_eat = get_time();
		if (pthread_mutex_init(&(*philo)[i].last_eat_mutex, NULL) != 0)
			return (-1);
		(*philo)[i].args = args;
		i++;
	}
	return (0);
}

int	init_mutex(t_args *args)
{
	int	i;

	args->fork = malloc(sizeof(pthread_mutex_t) * args->num_of_philo);
	if (!args->fork)
		return (-1);
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_init(&args->fork[i], NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&args->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&args->finished_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&args->end_philo_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&args->start_mutex, NULL) != 0)
		return (-1);
	return (0);
}

int	init_args(t_args *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->num_of_philo < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		return (-1);
	if (argc == 6)
	{
		data->num_of_must_eat = ft_atoi(argv[5]);
		if (data->num_of_must_eat < 1)
			return (-1);
	}
	else
		data->num_of_must_eat = 0;
	data->finished = 0;
	data->end_philo = 0;
	data->start_time = get_time();
	return (0);
}
