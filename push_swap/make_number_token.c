/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_number_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:56:25 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 15:16:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_number_token(char **string_token, int	*number_size)
{
	int	idx;
	int	*ret;

	idx = 0;
	*number_size = token_size(string_token);
	ret = malloc(sizeof(int) * (*number_size));
	if (ret == NULL)
		print_error();
	while (idx < (*number_size))
	{
		if (ft_strlen(string_token[idx]) > 10)
			print_error();
		if (ft_strlen(string_token[idx]) != 0)
			ret[idx] = make_number(string_token[idx]);
		idx++;
	}
	return (ret);
}

int	make_number(char *str)
{
	long long	ret;
	int			neg;

	neg = 1;
	ret = 0;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || '9' < *str)
			print_error();
		ret *= 10;
		ret += (*str) - '0';
		str++;
	}
	ret *= neg;
	if (ret < -2147483648 || ret > 2147483647)
		print_error();
	return (ret);
}
