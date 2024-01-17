/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:35:42 by kyumkim           #+#    #+#             */
/*   Updated: 2024/01/17 20:05:07 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*make_return(char	**buffer);
char	*ft_strdup(char *str);
char	*ft_strnstr(char **str, int endidx);
void	str_ncpy(char *dest, char *src, int n);
int		readfile(char **buffer, int fd);
int		ft_strcat(char **dest, char *src);
int		ft_strlen(char *str);
int		newline_idx(char *str);

#endif