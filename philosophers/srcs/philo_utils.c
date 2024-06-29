/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:14:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/29 13:53:51 by kyuminkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *msg)
{
	long long	time;

	pthread_mutex_lock(&philo->args->finished_mutex);
	if (philo->args->finished)
	{
		pthread_mutex_unlock(&philo->args->finished_mutex);
		return ;
	}
	time = get_time() - philo->args->start_time;
	pthread_mutex_lock(&philo->args->print);
	printf("%lld %d %s\n", time, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->args->print);
	pthread_mutex_unlock(&philo->args->finished_mutex);
}

void	checker_print(t_args *args, int philo_num, char *msg)
{
	long long	time;

	time = get_time() - args->start_time;
	pthread_mutex_lock(&args->print);
	printf("%lld %d %s\n", time, philo_num + 1, msg);
	pthread_mutex_unlock(&args->print);
}

int	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	ret = (long long)time.tv_sec * 1000 + (time.tv_usec / 1000);
	return (ret);
}

int	free_philo(t_args *args, t_philo *philo, int i)
{
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_destroy(&philo[i].eat_count_mutex))
			return (1);
		if (pthread_mutex_destroy(&philo[i].last_eat_mutex))
			return (1);
		i++;
	}
	free(philo);
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_destroy(&args->fork[i++]))
			return (1);
	}
	free(args->fork);
	if (pthread_mutex_destroy(&args->print))
		return (1);
	if (pthread_mutex_destroy(&args->finished_mutex))
		return (1);
	if (pthread_mutex_destroy(&args->end_philo_mutex))
		return (1);
	if (pthread_mutex_destroy(&args->start_mutex))
		return (1);
	return (0);
}
