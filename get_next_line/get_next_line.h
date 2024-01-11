/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:44:02 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/29 18:27:08 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 15

typedef struct s_list
{
	char			*data;
	int				fd;
	int				end;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*make_return(char	**buffer);
char	*ft_strnstr(char **str, int endidx);
int	readfile(char **buffer, int fd);
int	ft_strcat(char **dest, char *src);
int ft_strlen(char *str);
int	newline_idx(char *str);


#endif