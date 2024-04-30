/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:55:21 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 15:11:49 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3num(t_stack_set *set, int rflag)
{
	t_node	*n1;
	t_node	*n2;

	n1 = set->stack_a->first;
	n2 = n1->next;
	if (n2->index - n1->index == -1 || n2->next->index - n2->index == -1)
	{
		sa(set);
	}
	if (n2->index - n1->index == -2)
	{
		if (rflag)
			rr(set);
		else
			ra(set);
	}
	else if (n2->next->index - n2->index == -2)
	{
		if (rflag)
			rrr(set);
		else
			rra(set);
	}
}

void	sort_4num(t_stack_set *set)
{
	small_num_a_to_b(set, 0);
	sort_3num(set, 0);
	pa(set);
}

void	sort_5num(t_stack_set *set)
{
	t_stack	*a;

	a = set->stack_a;
	small_num_a_to_b(set, 0);
	small_num_a_to_b(set, 1);
	if (set->stack_b->first->index == 0)
		sort_3num(set, 1);
	else
		sort_3num(set, 0);
	pa(set);
	pa(set);
}

void	small_num_a_to_b(t_stack_set *set, int idx)
{
	t_node	*tmp;
	int		move;

	tmp = set->stack_a->first;
	move = find_index_in_stack(set->stack_a, idx);
	if (move > set->stack_a->size / 2)
	{
		move = set->stack_a->size - move;
		while (move--)
			rra(set);
	}
	else
	{
		while (move--)
			ra(set);
	}
	pb(set);
}

void	sort_small_num(int number_size, t_stack_set *set)
{
	if (number_size == 2)
	{
		sa(set);
		return ;
	}
	else if (number_size == 3)
		sort_3num(set, 0);
	else if (number_size == 4)
		sort_4num(set);
	else if (number_size == 5)
		sort_5num(set);
}
