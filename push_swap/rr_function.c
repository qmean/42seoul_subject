/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:40:02 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/23 22:35:34 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rra(t_stack_set *set)
{
	t_stack	*a;
	t_node	*tmp;

	if (set->stack_a->size < 2)
		return ;
	a = set->stack_a;
	tmp = a->last;
	a->last = a->last->prev;
	a->last->next = NULL;
	tmp->next = a->first;
	a->first->prev = tmp;
	a->first = tmp;
	tmp->prev = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_set *set)
{
	t_stack	*b;
	t_node	*tmp;

	if (set->stack_b->size < 2)
		return ;
	b = set->stack_b;
	tmp = b->last;
	b->last = b->last->prev;
	b->last->next = NULL;
	tmp->next = b->first;
	b->first->prev = tmp;
	b->first = tmp;
	tmp->prev = NULL;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_set *set)
{
	rra(set);
	rrb(set);
	ft_putstr_fd("rrr\n", 1);
}
