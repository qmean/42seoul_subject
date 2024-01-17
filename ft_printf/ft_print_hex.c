/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:14:17 by kyumkim           #+#    #+#             */
/*   Updated: 2024/01/17 19:06:38 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lowhex(unsigned long n, int fd);
int	print_uphex(unsigned long n, int fd);

int	ft_print_pointer(void *inp, int fd)
{
	int	ret;
	int	tmp;

	ret = 2;
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	tmp = print_lowhex((unsigned long)inp, fd);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	return (ret);
}

int	ft_print_hexlow(void *inp, int fd)
{
	int	ret;

	ret = print_lowhex((unsigned int)inp, fd);
	return (ret);
}

int	print_lowhex(unsigned long n, int fd)
{
	int	ret;
	int	tmp;

	ret = 1;
	if (n > 15)
	{
		tmp = print_lowhex(n / 16, fd);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(fd, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (ret);
}

int	ft_print_hexup(void *inp, int fd)
{
	int	ret;

	ret = print_uphex((unsigned int)inp, fd);
	return (ret);
}

int	print_uphex(unsigned long n, int fd)
{
	int	ret;
	int	tmp;

	ret = 1;
	if (n > 15)
	{
		tmp = print_uphex(n / 16, fd);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(fd, &"0123456789ABCDEF"[n % 16], 1) == -1)
		return (-1);
	return (ret);
}
