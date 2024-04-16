/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:36:07 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/17 00:54:32 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	sorted_factor(t_stack_set *set)
{
	free_stack(set->stack_a);
	free_stack(set->stack_b);
	exit(0);
}

void	free_stack(t_stack	*stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack->first;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}
