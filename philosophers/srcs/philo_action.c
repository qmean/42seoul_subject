/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:34:43 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/22 02:36:51 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->fork[philo->left]);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->args->fork[philo->right]);
	philo_print(philo, "has taken a fork");
	philo_print(philo, "is eating");
	philo->last_eat = get_time();
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->args->fork[philo->left]);
	pthread_mutex_unlock(&philo->args->fork[philo->right]);
	philo->eat_count++;
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