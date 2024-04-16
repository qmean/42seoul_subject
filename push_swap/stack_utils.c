/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:51:48 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/17 00:14:52 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(1);
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	push_front(t_stack	*stack, t_node *data)
{
	t_node	*tmp;

	tmp = data;
	if (stack->first == NULL && stack->last == NULL)
	{
		stack->first = tmp;
		stack->last = tmp;
		stack->size = 1;
		return ;
	}
	tmp->next = stack->first;
	stack->first->prev = tmp;
	stack->first = tmp;
	stack->size = stack->size + 1;
}

void	push_back(t_stack	*stack, t_node *data)
{
	t_node	*tmp;

	tmp = data;
	if (stack->first == NULL && stack->last == NULL)
	{
		stack->first = tmp;
		stack->last = tmp;
		stack->size = 1;
		return ;
	}
	tmp->prev = stack->last;
	stack->last->next = tmp;
	stack->last = tmp;
	stack->size = stack->size + 1;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->first;
	if (stack->size == 1)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->first = tmp->next;
		stack->first->prev = NULL;
	}
	stack->size = stack->size - 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->last;
	if (stack->size == 1)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->last = tmp->prev;
		stack->last->next = NULL;
	}
	stack->size = stack->size - 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}
