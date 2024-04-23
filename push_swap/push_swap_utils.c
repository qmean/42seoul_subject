/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:11:27 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/24 00:34:14 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node	*a, t_node	*b)
{
	int		tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_node	*find_node_in_stack(t_stack *stack, int data)
{
	t_node	*cur;

	cur = stack->first;
	while (cur != NULL)
	{
		if (cur->data == data)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int	find_index_in_stack(t_stack *stack, int index)
{
	t_node	*cur;
	int		ret;

	ret = 0;
	cur = stack->first;
	while (cur != NULL)
	{
		if (cur->index == index)
			return (ret);
		cur = cur->next;
		ret++;
	}
	return (ret);
}
