/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:54:44 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/16 19:14:31 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_set *set)
{
	t_stack		*a;
	t_stack		*b;

	a = set->stack_a;
	b = set->stack_b;
	if (b->size < 1)
		return ;
	push_front(a, pop_front(b));
}

void	pb(t_stack_set *set)
{
	t_stack		*a;
	t_stack		*b;

	a = set->stack_a;
	b = set->stack_b;
	if (a->size < 1)
		return ;
	push_front(b, pop_front(a));
}
