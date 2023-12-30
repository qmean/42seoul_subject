/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:44:30 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/30 09:56:04 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[_SC_OPEN_MAX];

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = (char *)malloc(BUFFER_SIZE + 1);
	if (readfile(&buffer[fd], fd) == -1)
		return (NULL);
}

int	readfile(char **buffer, int fd)
{
	if (newline_idx(*buffer) == 0)
	{
		
	}
}

int	newline_idx(char *str)
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
