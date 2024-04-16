/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/17 00:54:31 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				index;
}t_node;

typedef struct s_stack
{
	t_node		*first;
	t_node		*last;
	int			size;
}t_stack;

typedef struct s_stack_set
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}t_stack_set;

void	swap(t_node	*a, t_node	*b);

t_node	*new_node(int data);
void	push_front(t_stack	*stack, t_node *node);
void	push_back(t_stack	*stack, t_node *node);
t_node	*pop_front(t_stack *stack);
t_node	*pop_back(t_stack *stack);

void	sa(t_stack_set *set);
void	sb(t_stack_set *set);
void	ss(t_stack_set *set);

void	pa(t_stack_set *set);
void	pb(t_stack_set *set);

void	ra(t_stack_set	*set);
void	rb(t_stack_set	*set);
void	rr(t_stack_set	*set);

void	rra(t_stack_set *set);
void	rrb(t_stack_set *set);
void	rrr(t_stack_set *set);

void	print_error(void);
void	sorted_factor(t_stack_set *set);
void	free_stack(t_stack	*stack);

#endif