/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:54:53 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/30 17:17:10 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			number_size;
	int			*number_token;
	char		**string_token;
	t_stack_set	*set;

	if (argc < 2)
		exit(0);
	string_token = make_string_token(argc, argv);
	number_token = make_number_token(string_token, &number_size);
	check_same_num(number_token, number_size);
	if (check_sorted(number_token, number_size))
	{
		free_tokens(string_token, number_token);
		return (0);
	}
	set = (t_stack_set *)malloc(sizeof(t_stack_set));
	if (set == NULL)
		exit(1);
	sort(number_token, number_size, set);
	before_return(string_token, number_token, set);
	return (0);
}
