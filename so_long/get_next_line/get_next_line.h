/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:44:02 by kyumkim           #+#    #+#             */
/*   Updated: 2024/02/28 13:30:36 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*make_return(char	**buffer);
char	*ft_strdup(char *str);
char	*ft_substr(char **str, int endidx);
void	str_ncpy(char *dest, char *src, int n);
int		readfile(char **buffer, int fd);
int		ft_strcat(char **dest, char *src);
int		ft_strlen(char *str);
int		newline_idx(char *str);
void	free_buffer(char **str, char *tmp);

#endif
