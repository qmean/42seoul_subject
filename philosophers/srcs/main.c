/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:02:51 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/22 03:11:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv) {
	t_args args;
	t_philo *philo;

	if (argc != 5 && argc != 6) {
		print_error("Error: Invalid arguments\n");
	}
	init_args(&args, argc, argv);
	init_mutex(&args);
	init_philo(&args, &philo);
	start_philo(&args, philo);
}

void check_finished(t_args *args, t_philo *philo);

void start_philo(t_args *args, t_philo *philo)
{
	int i;

	i = 0;
	args->start_time = get_time();
	while (i < args->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			print_error("Error: Failed to create thread\n");
		i++;
	}
	check_finished(args, philo);
	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			print_error("Error: Failed to join thread\n");
		i++;
	}
}

void check_finished(t_args *args, t_philo *philo)
{
	int	i;

	while (!args->finished) {
		if ((args->num_of_must_eat != 0) && (args->num_of_philo >= args->end_philo)) {
			args->finished = 1;
			break;
		}
		i = 0;
		while (i < args->num_of_philo) {
			if (get_time() - philo[i].last_eat > args->time_to_die * 1000) {
				args->finished = 1;
				break;
			}
			i++;
		}
	}
}

void *routine(void *philo)
{
	t_philo *args;

	args = (t_philo *)philo;
	while(!args->args->finished)
	{
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
	}
	return (0);
}

void	philo_print(t_philo *args, char *msg)
{
	long long	time;

	time = get_time() - args->args->start_time;
	pthread_mutex_lock(&args->args->print);
	printf("%lld %d %s\n", time, args->id + 1, msg);
	pthread_mutex_unlock(&args->args->print);
}

void print_error(char *msg) {
	ft_putstr_fd(msg, 2);
	exit(1);
}

long long	get_time()
{
	struct timeval time;
	long long		ret;

	gettimeofday(&time, NULL);
	if (time.tv_sec < 0)
		print_error("Error: Failed to get time\n");
	if (time.tv_usec < 0)
		print_error("Error: Failed to get time\n");
	ret = (long long)time.tv_sec * 1000 + (time.tv_usec / 1000);
	return (ret);
}