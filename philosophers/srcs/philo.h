/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:07:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/22 03:07:22 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				finished;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	int 			end_philo;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				left;
	int 			right;
	int 			eat_count;
	long long		last_eat;
	pthread_t		thread;
	t_args			*args;
}					t_philo;

long long	get_time();
void print_error(char *msg);
void init_args(t_args *data, int argc, char **argv);
void init_mutex(t_args *args);
void init_philo(t_args *args, t_philo **philo);
void start_philo(t_args *args, t_philo *philo);
void	philo_print(t_philo *args, char *msg);
void *routine(void *);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

#endif