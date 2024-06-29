/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:34:43 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/29 20:31:11 by kyuminkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*cur_philo;

	cur_philo = (t_philo *)philo;
	pthread_mutex_lock(&cur_philo->args->start_mutex);
	pthread_mutex_unlock(&cur_philo->args->start_mutex);
	if (cur_philo->id % 2 == 0)
		usleep(cur_philo->args->time_to_eat * 100);
	while (1)
	{
		if (!check_finished_routine(cur_philo))
			philo_eat(cur_philo);
		else
			break ;
		if (cur_philo->args->num_of_philo == 1)
			break ;
		if (!check_finished_routine(cur_philo))
			philo_sleep(cur_philo);
		else
			break ;
		if (!check_finished_routine(cur_philo))
			philo_think(cur_philo);
		else
			break ;
		usleep(10);
	}
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (get_fork(philo) == 1)
		return ;
	philo_print(philo, "is eating");
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	while (get_time() - philo->last_eat < philo->args->time_to_eat)
		usleep(1000);
	philo->eat_count++;
	if (philo->eat_count == philo->args->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->args->end_philo_mutex);
		philo->args->end_philo++;
		philo->finished = 1;
		pthread_mutex_unlock(&philo->args->end_philo_mutex);
	}
	pthread_mutex_unlock(&philo->args->fork[philo->left]);
	pthread_mutex_unlock(&philo->args->fork[philo->right]);
}

int	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->fork[philo->left]);
	philo_print(philo, "has taken a fork");
	if (philo->args->num_of_philo == 1)
	{
		pthread_mutex_unlock(&philo->args->fork[philo->left]);
		return (1);
	}
	pthread_mutex_lock(&philo->args->fork[philo->right]);
	philo_print(philo, "has taken a fork");
	return (0);
}

void	philo_sleep(t_philo *philo)
{
	long long	time;

	philo_print(philo, "is sleeping");
	time = get_time();
	while (get_time() - time < philo->args->time_to_sleep)
		usleep(1000);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, "is thinking");
}
