/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:43:30 by kyumkim           #+#    #+#             */
/*   Updated: 2023/11/23 16:55:46 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf[BUFFER_SIZE];
	int			read_size;

	read_size = 0;
	while ((read_size = read(fd, buf, BUFFER_SIZE - 1)) != 0)
	{
		buf[read_size] = 0;
		if (next_line_in_str(buf) == 1)
			return (make_output(buf));
	}
}