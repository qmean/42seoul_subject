/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:25:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 10:57:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_set *set)
{
	t_stack		*a;

	a = set->stack_a;
	if (a->size < 2)
		return ;
	swap(a->first, a->first->next);
	ft_putstr_fd("sa\n", 1);
	return ;
}

void	sb(t_stack_set *set)
{
	t_stack		*b;

	b = set->stack_b;
	if (b->size < 2)
		return ;
	swap(b->first, b->first->next);
	ft_putstr_fd("sb\n", 1);
	return ;
}

void	ss(t_stack_set *set)
{
	sa(set);
	sb(set);
	ft_putstr_fd("ss\n", 1);
}
