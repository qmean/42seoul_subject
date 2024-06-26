/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:34:43 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/26 21:04:38 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->fork[philo->left]);
	philo_print(philo, "has taken a fork");
	if (philo->args->num_of_philo == 1)
	{
		pthread_mutex_unlock(&philo->args->fork[philo->left]);
		exit(0);
	}
	pthread_mutex_lock(&philo->args->fork[philo->right]);
	philo_print(philo, "has taken a fork");
	philo_print(philo, "is eating");
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_lock(&philo->eat_count_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_count_mutex);
	pthread_mutex_lock(&philo->args->end_philo_mutex);
	if (philo->eat_count == philo->args->num_of_must_eat)
	{
		philo->args->end_philo++;
		philo->finished = 1;
	}
	pthread_mutex_unlock(&philo->args->end_philo_mutex);
	pthread_mutex_unlock(&philo->args->fork[philo->right]);
	pthread_mutex_unlock(&philo->args->fork[philo->left]);
}

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	usleep(philo->args->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, "is thinking");
}
