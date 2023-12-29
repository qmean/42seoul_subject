/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:43:30 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/29 18:50:41 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*ret;
	t_list			*tmp;
	int				read_flag;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		if (addfront(&lst, fd) == -1)
			return (NULL);
		tmp = lst;
	read_flag = readfile(&tmp->data, fd);
	if (read_flag == -1)
		return (NULL);
	else if (read_flag == 1)
		ret = lastread(tmp);
	ret = makeret(lst->data);
	if (cutnewline(lst) == -1)
		return (NULL);
	return (ret);
}

char	*lastread(t_list *lst)
{
	char	*ret;

	if (lst->end == 1)
		return (NULL);
	else
	{
		ret = (char *)malloc(ft_strlen(lst->data) + 1);
		ft_strdup(ret, lst->data);
		free(lst->data);
		lst->end = 1;
		lst->data = NULL;
	}
	return (ret);
}

int	cutnewline(t_list *lst)
{
	int		lineidx;
	int		idx;
	char	*str;

	lineidx = newline_idx(lst->data);
	if (lst->end == 1)
	{
		free(lst->data);
		return (0);
	}
	str = (char *)malloc(ft_strlen(lst->data) - lineidx);
	if (str == NULL)
		return (-1);
	idx = 0;
	while (lst->data[lineidx + idx + 1] != 0)
	{
		str[idx] = lst->data[lineidx + idx + 1];
		idx++;
	}
	str[idx] = 0;
	free(lst->data);
	lst->data = str;
	return (0);
}

char	*makeret(char *str)
{
	int		lineidx;
	int		idx;
	char	*ret;

	lineidx = newline_idx(str);
	if (lineidx == 0)
		ret = (char *)malloc(ft_strlen(str) + 1);
	else
		ret = (char *)malloc(lineidx + 2);
	if (ret == NULL)
		return (NULL);
	idx = 0;
	while (*str != '\n' && *str != 0)
	{
		ret[idx] = *str;
		idx++;
		str++;
	}
	if (*str == '\n')
		ret[idx++] = '\n';
	ret[idx] = 0;
	return (ret);
}

int	readfile(char **str, int fd)
{
	int		lineidx;
	char	buffer[BUFFER_SIZE];
	int		read_size;

	lineidx = 0;
	if (*str != NULL)
		lineidx = newline_idx(*str);
	while (lineidx == 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE - 1);
		if (read_size == -1)
			return (-1);
		else if (read_size == 0)
			return (1);
		buffer[read_size] = 0;
		lineidx = newline_idx(buffer);
		if (strsum(str, buffer) == -1)
			return (-1);
	}
	return (0);
}
