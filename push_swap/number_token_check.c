/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_token_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:34:32 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/20 22:19:55 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int *number_token, int size)
{
	int	index;
	int	cur;
	int	flag;

	index = 1;
	flag = 0;
	cur = number_token[0];
	while (index < size)
	{
		if (cur > number_token[index])
			flag = 1;
		cur = number_token[index];
		index++;
	}
	if (flag == 0)
		return (1);
	return (0);
}

void	check_same_num(int	*number_token, int size)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (index1 < size - 1)
	{
		index2 = index1 + 1;
		while (index2 < size)
		{
			if (number_token[index1] == number_token[index2])
				print_error();
			index2++;
		}
		index1++;
	}
}
