/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:07:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/26 20:45:36 by kyumkim          ###   ########.fr       */
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
	pthread_mutex_t	finished_mutex;
	pthread_mutex_t	end_philo_mutex;
	pthread_mutex_t start_mutex;
	int				end_philo;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				finished;
	int				left;
	int				right;
	int				eat_count;
	long long		last_eat;
	pthread_mutex_t	eat_count_mutex;
	pthread_mutex_t	last_eat_mutex;
	pthread_t		thread;
	t_args			*args;
}					t_philo;

long long	get_time(void);
void		print_error(char *msg);
void		init_args(t_args *data, int argc, char **argv);
void		init_mutex(t_args *args);
void		init_philo(t_args *args, t_philo **philo);
void		start_philo(t_args *args, t_philo *philo);
void		philo_print(t_philo *args, char *msg);
void		*routine(void *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
int			check_finished_routine(t_philo *philo);
void		check_finished(t_args *args, t_philo *philo, int i);
void		checker_print(t_args *args, int philo_num, char *msg);
void		free_philo(t_args *args, t_philo *philo);

#endif