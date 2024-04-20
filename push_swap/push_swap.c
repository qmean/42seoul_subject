/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:54:53 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/20 23:27:49 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_token(char **string_token);
void print_nubmer_token(int	*token, int size);

void check_leak(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	int			number_size;
	int			*number_token;
	char		**string_token;
	t_stack_set	*set;

	if (argc < 2)
		print_error();
	/*
	파싱
	*/
	string_token = make_string_token(argc, argv);
	number_token = make_number_token(string_token, &number_size);
	/*
	파싱된 결과 검사
	*/
	check_same_num(number_token, number_size);
	if (check_sorted(number_token, number_size))
	{
		free_tokens(string_token, number_token);
		atexit(check_leak);
		return (0);
	}
	/*
	정렬 로직 수행
	*/
	set = malloc(sizeof(t_stack_set));
	sort(number_token, number_size, set);
	print_nubmer_token(number_token, number_size);
	/*
	리턴하기전 메모리 해제
	*/
	before_return(string_token, number_token, set);
	atexit(check_leak);
	return (0);
}

#include <stdio.h>

void print_token(char **string_token)
{
	int idx = 0;

	while (string_token[idx] != NULL)
	{
		printf("%s\n", string_token[idx]);
		idx++;
	}
}

void print_nubmer_token(int	*token, int size)
{
	int idx = 0;
	while (idx < size)
	{
		printf("%d\n", token[idx]);
		idx++;
	}
}