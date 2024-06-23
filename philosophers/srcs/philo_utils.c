/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:14:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/23 21:21:27 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *args, char *msg)
{
	long long	time;

	if (check_finished_routine(args))
		return ;
	pthread_mutex_lock(&args->args->print);
	time = get_time() - args->args->start_time;
	printf("%lld %d %s\n", time, args->id + 1, msg);
	pthread_mutex_unlock(&args->args->print);
}

void	checker_print(t_args *args, char *msg)
{
	long long	time;

	pthread_mutex_lock(&args->print);
	time = get_time() - args->start_time;
	printf("%lld %s\n", time, msg);
	pthread_mutex_unlock(&args->print);
}

void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	if (time.tv_sec < 0)
		print_error("Error: Failed to get time\n");
	if (time.tv_usec < 0)
		print_error("Error: Failed to get time\n");
	ret = (long long)time.tv_sec * 1000 + (time.tv_usec / 1000);
	return (ret);
}

void	free_philo(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_destroy(&philo[i].eat_count_mutex))
			print_error("Error: Failed to destroy mutex\n");
		if (pthread_mutex_destroy(&philo[i].last_eat_mutex))
			print_error("Error: Failed to destroy mutex\n");
		i++;
	}
	free(philo);
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_destroy(&args->fork[i]))
			print_error("Error: Failed to destroy mutex\n");
		i++;
	}
	if (pthread_mutex_destroy(&args->print))
		print_error("Error: Failed to destroy mutex\n");
	if (pthread_mutex_destroy(&args->finished_mutex))
		print_error("Error: Failed to destroy mutex\n");
	if (pthread_mutex_destroy(&args->end_philo_mutex))
		print_error("Error: Failed to destroy mutex\n");
}
