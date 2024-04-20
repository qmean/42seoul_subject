/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:53:18 by kyumkim           #+#    #+#             */
/*   Updated: 2024/04/20 21:47:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	**make_string_token(int argc, char **argv)
{
	int		idx;
	char	**string_token;

	idx = 1;
	string_token = ft_split(argv[idx], ' ');
	idx++;
	while (idx < argc)
	{
		string_token = token_push_back(string_token, ft_split(argv[idx], ' '));
		idx++;
	}
	return (string_token);
}

int	token_size(char **token)
{
	int	ret;
	int	idx;

	ret = 0;
	idx = 0;
	while (token[idx] != NULL)
	{
		ret++;
		idx++;
	}
	return (ret);
}

char	**token_push_back(char **dest, char **src)
{
	char	**ret;
	int		idx;
	int		idx2;

	idx = 0;
	ret = malloc(sizeof(char *) * (token_size(dest) + token_size(src) + 1));
	if (ret == NULL)
		exit(1);
	while (dest[idx] != NULL)
	{
		ret[idx] = dest[idx];
		idx++;
	}
	free(dest);
	idx2 = 0;
	while (src[idx2] != NULL)
	{
		ret[idx] = src[idx2];
		idx++;
		idx2++;
	}
	free(src);
	ret[idx] = NULL;
	return (ret);
}
