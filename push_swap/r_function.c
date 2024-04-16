/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:40:07 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/16 23:08:29 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_set	*set)
{
	t_stack	*a;
	t_node	*tmp;

	if (set->stack_a->size < 2)
		return ;
	a = set->stack_a;
	tmp = a->first;
	a->first = tmp->next;
	a->first->prev = NULL;
	a->last->next = tmp;
	tmp->prev = a->last;
	tmp->next = NULL;
	a->last = tmp;
}

void	rb(t_stack_set	*set)
{
	t_stack	*b;
	t_node	*tmp;

	if (set->stack_b->size < 2)
		return ;
	b = set->stack_b;
	tmp = b->first;
	b->first = tmp->next;
	b->first->prev = NULL;
	b->last->next = tmp;
	tmp->prev = b->last;
	tmp->next = NULL;
	b->last = tmp;
}

void	rr(t_stack_set	*set)
{
	ra(set);
	rb(set);
}
