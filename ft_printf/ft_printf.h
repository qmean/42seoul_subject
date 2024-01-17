/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:52:56 by kyumkim           #+#    #+#             */
/*   Updated: 2024/01/17 15:48:07 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define CHAR 1
# define STRING 2
# define POINTER 3
# define DECIMAL 4
# define INTEGER 5
# define UNSINGED 6
# define HEX_LOW 7
# define HEX_UPPER 8
# define PERCENT 9

int		ft_printf(const char *format, ...);

int		printing(char *format, va_list list);
int		check_specifier(char *first);
int		print_specifier(va_list list, int specifier);

int		ft_print_pointer(void *inp, int fd);
int		ft_print_hexlow(void *inp, int fd);
int		ft_print_hexup(void *inp, int fd);

int		ft_print_unsigned(unsigned int n, int fd);

int		ft_print_hexlow(void *inp, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);

#endif