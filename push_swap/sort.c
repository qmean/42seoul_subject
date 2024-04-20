/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:04:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/20 23:26:00 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *number_token, int number_size, t_stack_set *set)
{
	stack_init(set);
	push_token_to_stack(number_token, number_size, set);
	sort_number_token(number_token, number_size);
}

void	stack_init(t_stack_set *set)
{
	set->stack_a = malloc(sizeof(stack_t));
	if (set->stack_a == NULL)
		print_error();
	set->stack_b = malloc(sizeof(stack_t));
	if (set->stack_b == NULL)
		print_error();
}

void	push_token_to_stack(int *number_token, int size, t_stack_set *set)
{
	t_stack	*a;
	int		idx;

	a = set->stack_a;
	idx = 0;
	while (idx < size)
	{
		push_back(a, new_node(number_token[idx]));
		idx++;
	}
}

void	sort_number_token(int *number_token, int size)
{
	int	idx1;
	int	idx2;
	int	tmp;

	idx1 = 0;
	while (idx1 < size - 1)
	{
		idx2 = 0;
		while (idx2 < size - idx1 - 1)
		{
			if (number_token[idx2] > number_token[idx2 + 1])
			{
				tmp = number_token[idx2 + 1];
				number_token[idx2 + 1] = number_token[idx2];
				number_token[idx2] = tmp;
			}
			idx2++;
		}
		idx1++;
	}
}
