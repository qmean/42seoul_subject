/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:07:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/27 00:55:29 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	int				end_philo;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	finished_mutex;
	pthread_mutex_t	end_philo_mutex;
	pthread_mutex_t	start_mutex;
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
int			print_error(char *msg);
int			init_args(t_args *data, int argc, char **argv);
int			init_mutex(t_args *args);
int			init_philo(t_args *args, t_philo **philo);
int			start_philo(t_args *args, t_philo *philo);
int			free_philo(t_args *args, t_philo *philo, int i);
void		philo_print(t_philo *philo, char *msg);
void		*routine(void *philo);
void		philo_eat(t_philo *philo);
int			get_fork(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
int			check_finished_routine(t_philo *philo);
void		check_finished(t_args *args, t_philo *philo);
int			check_died_philo(t_args *args, t_philo *philo);
int			check_end_philo(t_args *args);
void		checker_print(t_args *args, int philo_num, char *msg);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);

#endif