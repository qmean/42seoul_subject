/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:47:37 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/29 18:39:57 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*str != 0)
	{
		str++;
		ret++;
	}
	return (ret);
}

int newline_idx(char *str)
{
	int	ret;

	if (str == NULL)
		return (0);
	ret = 0;
	while (*str != 0)
	{
		if (*str == '\n')
			return (ret);
		ret++;
		str++;
	}
	return (0);
}

int addfront(t_list **lst, int fd)
{
	t_list  *new;
	t_list  *tmp;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (-1);
	new->data = NULL;
	new->fd = fd;
	new->next = *lst;
	new->end = 0;
	*lst = new;
	return (0);
}