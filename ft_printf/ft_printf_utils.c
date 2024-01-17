/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:57:08 by kyumkim           #+#    #+#             */
/*   Updated: 2024/01/17 18:14:21 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printing(char *format, va_list list)
{
	int	specifier;
	int	ret;
	int	tmp;

	ret = 0;
	while (*format != '\0')
	{
		specifier = check_specifier(format);
		if (specifier)
		{
			tmp = print_specifier(list, specifier);
			if (tmp == -1)
				return (-1);
			ret += tmp;
			format += 2;
		}
		else
		{
			if (ft_putchar_fd(*format, 1) == -1)
				return (-1);
			format++;
			ret++;
		}
	}
	return (ret);
}

int	check_specifier(char *first)
{
	char	*second;

	second = first + 1;
	if (*first == '%')
	{
		if (*second == 'c')
			return (CHAR);
		else if (*second == 's')
			return (STRING);
		else if (*second == 'p')
			return (POINTER);
		else if (*second == 'd')
			return (DECIMAL);
		else if (*second == 'i')
			return (INTEGER);
		else if (*second == 'u')
			return (UNSINGED);
		else if (*second == 'x')
			return (HEX_LOW);
		else if (*second == 'X')
			return (HEX_UPPER);
		else if (*second == '%')
			return (PERCENT);
	}
	return (0);
}

int	print_specifier(va_list list, int specifier)
{
	if (specifier == CHAR)
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (specifier == STRING)
		return (ft_putstr_fd(va_arg(list, char *), 1));
	else if (specifier == POINTER)
		return (ft_print_pointer(va_arg(list, void *), 1));
	else if (specifier == DECIMAL)
		return (ft_putnbr_fd(va_arg(list, int), 1));
	else if (specifier == INTEGER)
		return (ft_putnbr_fd(va_arg(list, int), 1));
	else if (specifier == UNSINGED)
		return (ft_print_unsigned(va_arg(list, int), 1));
	else if (specifier == HEX_LOW)
		return (ft_print_hexlow(va_arg(list, void *), 1));
	else if (specifier == HEX_UPPER)
		return (ft_print_hexup(va_arg(list, void *), 1));
	else if (specifier == PERCENT)
		return (ft_putchar_fd('%', 1));
	return (-1);
}
