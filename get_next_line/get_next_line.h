/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:44:02 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/22 15:31:37 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100

typedef struct s_list
{
	char	data[BUFFER_SIZE];
	int		fd;
	t_list	*next;
}	t_list;


char	*get_next_line(int fd);
char	*make_output(char *str);
size_t	ft_strlen(char *c);

int		next_line_in_str(char *str);

#endif