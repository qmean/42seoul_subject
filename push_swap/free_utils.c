/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:21:15 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/20 23:30:57 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **string_token, int *number_token)
{
	free_string_token(string_token);
	free(number_token);
	free(string_token);
}

void	free_string_token(char **string_token)
{
	int	idx;

	idx = 0;
	while (string_token[idx] != NULL)
	{
		free(string_token[idx]);
		idx++;
	}
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

void	before_return(char **string_token, int *number_token, t_stack_set *set)
{
	free_tokens(string_token, number_token);
	free_stack(set->stack_a);
	free_stack(set->stack_b);
	free(set->stack_a);
	free(set->stack_b);
	free(set);
}
