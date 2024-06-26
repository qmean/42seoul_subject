/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 15:17:42 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "libft/libft.h"

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
t_node	*find_node_in_stack(t_stack *stack, int data);
int		find_index_in_stack(t_stack *stack, int index);

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

int		check_sorted(int *number_token, int size);
void	check_same_num(int	*number_token, int size);

char	**make_string_token(int argc, char **argv);
int		token_size(char **token);
char	**token_push_back(char **dest, char **src);

int		make_number(char *str);
int		*make_number_token(char **string_token, int	*number_size);

void	free_tokens(char **string_token, int *number_token);
void	free_string_token(char **string_token);
void	free_stack(t_stack	*stack);
void	before_return(char **string_token, int *number_token, t_stack_set *set);

void	sort(int *number_token, int number_size, t_stack_set *set);
void	sort_number_token(int *number_token, int size);
void	push_token_to_stack(int *number_token, int size, t_stack_set *set);
void	stack_init(t_stack_set *set);
void	make_stack_index(t_stack_set *set, int *number_token, int number_size);

void	a_to_b(t_stack_set *set, int chunk);
void	b_to_a(t_stack_set *set, int num_size);

void	sort_small_num(int number_size, t_stack_set *set);
void	sort_3num(t_stack_set *set, int rflag);
void	sort_4num(t_stack_set *set);
void	sort_5num(t_stack_set *set);
void	small_num_a_to_b(t_stack_set *set, int idx);

#endif