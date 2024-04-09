/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:50:14 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/09 23:47:03 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_signal(int signo)
{
	static char	prtc;
	static int	cnt;

	if (signo == SIGUSR1)
	{
		prtc |= 0;
		if (cnt != 7)
			prtc <<= 1;
	}
	else
	{
		prtc |= 1;
		if (cnt != 7)
			prtc <<= 1;
	}
	cnt++;
	if (cnt == 8)
	{
		write(1, &prtc, 1);
		cnt = 0;
		prtc = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, send_signal);
	signal(SIGUSR2, send_signal);
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
