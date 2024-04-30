/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:04:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 15:12:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *number_token, int number_size, t_stack_set *set)
{
	stack_init(set);
	push_token_to_stack(number_token, number_size, set);
	sort_number_token(number_token, number_size);
	make_stack_index(set, number_token, number_size);
	if (number_size <= 5)
	{
		sort_small_num(number_size, set);
		return ;
	}
	a_to_b(set, (int)(14.5 + 3 * number_size / 100));
	b_to_a(set, number_size);
}

void	stack_init(t_stack_set *set)
{
	set->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (set->stack_a == NULL)
		print_error();
	set->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (set->stack_b == NULL)
		print_error();
	set->stack_a->first = NULL;
	set->stack_a->last = NULL;
	set->stack_b->first = NULL;
	set->stack_b->last = NULL;
}

void	push_token_to_stack(int *number_token, int size, t_stack_set *set)
{
	t_stack	*a;
	t_node	*tmp;
	int		idx;

	a = set->stack_a;
	idx = 0;
	while (idx < size)
	{
		tmp = new_node(number_token[idx]);
		push_back(a, tmp);
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

void	make_stack_index(t_stack_set *set, int *number_token, int number_size)
{
	int		idx;
	t_node	*tmp;

	idx = 0;
	while (idx < number_size)
	{
		tmp = find_node_in_stack(set->stack_a, number_token[idx]);
		tmp->index = idx;
		idx++;
	}
}
