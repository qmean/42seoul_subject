/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:12:02 by kyumkim           #+#    #+#             */
/*   Updated: 2024/01/17 19:05:22 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printuns(unsigned int n, int fd);

int	ft_print_unsigned(unsigned int n, int fd)
{
	int	ret;

	if (fd < 0)
		return (-1);
	ret = printuns(n, fd);
	return (ret);
}

int	printuns(unsigned int n, int fd)
{
	int	ret;
	int	tmp;

	ret = 1;
	if (n > 9)
	{
		tmp = printuns(n / 10, fd);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(fd, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (ret);
}
