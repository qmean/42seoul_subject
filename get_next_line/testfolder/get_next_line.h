/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:44:02 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/29 19:01:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

//# define BUFFER_SIZE

typedef struct s_list
{
	char			*data;
	int				fd;
	int				end;
	struct s_list	*next;
}	t_list;

int		addfront(t_list **lst, int fd);
char	*get_next_line(int fd);
int		cutnewline(t_list *lst);
char	*makeret(char *str);
int		readfile(char **str, int fd);
int		strsum(char **dest, char *src);
int		ft_strlen(char *str);
int		newline_idx(char *str);
char	*lastread(t_list *lst);
void	ft_strdup(char *dest, char *src);

#endif