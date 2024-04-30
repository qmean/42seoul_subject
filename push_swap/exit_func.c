/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:36:07 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 15:38:31 by kyumkim          ###   ########.fr       */
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
