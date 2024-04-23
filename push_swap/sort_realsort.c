/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_realsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:36:29 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/24 00:40:40 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack_set *set, int chunk)
{
	t_stack	*a;
	int		p_count;
	int		index;

	p_count = 0;
	a = set->stack_a;
	while (a->size != 0)
	{
		index = a->first->index;
		if (index <= p_count)
		{
			pb(set);
			p_count++;
		}
		else if (p_count < index && index <= p_count + chunk)
		{
			pb(set);
			p_count++;
			rb(set);
		}
		else if (p_count + chunk < a->first->index)
			ra(set);
	}
}

void	b_to_a(t_stack_set *set, int num_size)
{
	t_stack	*b;
	int		index;
	int		move;

	index = num_size - 1;
	b = set->stack_b;
	while (b->size != 0)
	{
		move = find_index_in_stack(b, index);
		if (move > (b->size) / 2)
		{
			move = (b->size) - move;
			while (move--)
				rrb(set);
			pa(set);
		}
		else
		{
			while (move--)
				rb(set);
			pa(set);
		}
		index--;
	}
}
