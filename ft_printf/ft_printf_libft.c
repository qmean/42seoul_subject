/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/01/17 19:04:28 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnum(long long n, int fd);

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s != 0)
	{
		ret++;
		s++;
	}
	return (ret);
}

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (-1);
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	ret;

	if (fd < 0)
		return (-1);
	ret = printnum((long long)n, fd);
	return (ret);
}

int	printnum(long long n, int fd)
{
	int	ret;
	int	tmp;

	ret = 1;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		n *= -1;
		ret++;
	}
	if (n > 9)
	{
		tmp = printnum(n / 10, fd);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(fd, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (ret);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return (-1);
	if (s == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (ft_strlen(s));
}
