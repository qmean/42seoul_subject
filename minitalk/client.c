/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:50:21 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/09 23:50:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_server_pid;

int	send_character(char c)
{
	int	cnt;

	cnt = 7;
	while (cnt >= 0)
	{
		if (((c >> cnt) & 1) == 0)
		{
			if (kill(g_server_pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(g_server_pid, SIGUSR2) == -1)
				return (-1);
		}
		usleep(100);
		cnt--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("bad arguments\n", 1);
		return (0);
	}
	g_server_pid = ft_atoi(argv[1]);
	if (g_server_pid < 100 || g_server_pid > 99998)
	{
		ft_putstr_fd("pid error\n", 1);
		return (0);
	}
	while (*(argv[2]) != 0)
	{
		if (send_character(*(argv[2])) == -1)
		{
			ft_putstr_fd("signal error\n", 1);
			return (0);
		}
		argv[2]++;
	}
	return (0);
}
