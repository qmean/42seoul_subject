/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:14:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/22 02:53:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_args *args, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * args->num_of_philo);
	if (!*philo)
		print_error("Error: Failed to allocate philosophers\n");
	i = 0;
	while (i < args->num_of_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % args->num_of_philo;
		(*philo)[i].eat_count = 0;
		(*philo)[i].last_eat = get_time();
		(*philo)[i].args = args;
		i++;
	}
}

void init_mutex(t_args *args)
{
	int	i;

	args->fork = malloc(sizeof(pthread_mutex_t) * args->num_of_philo);
	if (!args->fork)
		print_error("Error: Failed to allocate mutex\n");
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_init(&args->fork[i], NULL) != 0)
			print_error("Error: Failed to initialize mutex\n");
		i++;
	}
}

void init_args(t_args *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	if (data->num_of_philo < 0)
		print_error("Error: Invalid number of philosophers\n");
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die < 0)
		print_error("Error: Invalid time to die\n");
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat < 0)
		print_error("Error: Invalid time to eat\n");
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep < 0)
		print_error("Error: Invalid time to sleep\n");
	if (argc == 6)
	{
		data->num_of_must_eat = ft_atoi(argv[5]);
		if (data->num_of_must_eat < 0)
			print_error("Error: Invalid number of times each philosopher must eat\n");
	}
	else
		data->num_of_must_eat = 0;
	data->start_time = get_time();
	data->finished = 0;
	data->end_philo = 0;
}
