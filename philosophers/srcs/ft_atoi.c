/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:49 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/29 19:59:00 by kyuminkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	inp;

	inp = 0;
	if (*str == '-' || *str == '+' || *str == '\0')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		inp *= 10;
		inp += *str - '0';
		str++;
		if (inp > 2147483647)
			return (-1);
	}
	return (inp);
}
