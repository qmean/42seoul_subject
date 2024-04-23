/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:40:07 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/23 22:35:19 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
	ft_putstr_fd("ra\n", 1);
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
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_set	*set)
{
	ra(set);
	rb(set);
	ft_putstr_fd("rr\n", 1);
}
