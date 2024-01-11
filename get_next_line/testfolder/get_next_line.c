/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:44:30 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/30 18:33:46 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];

	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (readfile(&buffer[fd], fd) == -1)
    {
        free(buffer[fd]);
		return (NULL);
    }
	return (make_return(&buffer[fd]));
}

char	*make_return(char	**buffer)
{
	int	lineidx;
	
	lineidx = newline_idx(*buffer);
	if (lineidx == -1)
		return (ft_strnstr(buffer, ft_strlen(*buffer) - 1));
	else
		return (ft_strnstr(buffer, lineidx));
}

char    *ft_strdup(char *str)
{
    char    *ret;
    int     retidx;

    if (str == NULL)
        return (NULL);
    ret = malloc(ft_strlen(str) + 1);
    retidx = 0;
    while (*str != 0)
    {
        ret[retidx] = *str;
        retidx++;
        str++;
    }
    ret[retidx] = 0;
    return (ret);
}
char	*ft_strnstr(char **str, int endidx)
{
	char	*ret;
	char	*tmp;
    char    *freeptr;
	int		idx;


    if ((ft_strlen(*str) - endidx) == 0)
    {
        ret = ft_strdup(*str);
        free(*str);
        *str = NULL;
        return (ret);
    }
    ret = malloc(endidx + 2);
    tmp = malloc(ft_strlen(*str) - endidx);
	if (ret == NULL || tmp == NULL)
		return (NULL);
	idx = 0;
    freeptr = *str;
	while (idx <= endidx)
	{
		ret[idx++] = **str;
        (*str)++;
	}
	ret[idx] = 0;
	idx = 0;
	while (**str != 0)
	{
		tmp[idx++] = **str;
        (*str)++;
	}
	tmp[idx] = 0;
	free(freeptr);
	*str = tmp;
	return (ret);
}

int	readfile(char **buffer, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		read_size;
	// read -1 일때 -1 리턴
	// 파일의 끝에 도달했고(read가 0이고) 버퍼에 아무것도 없을때 -1 리턴
	// 굳이 더 읽을 필요가 없을 때(이미 버퍼에 개행이 있을 때) 바로 0 리턴
	if (newline_idx(*buffer) != -1)
		return (0);
	while(newline_idx(*buffer) == -1)
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
			return (-1);
		else if (read_size == 0)
        {
			if (ft_strlen(*buffer) == 0)
				return (-1);
			break ;
        }
		tmp[read_size] = 0;
		if (ft_strcat(buffer, tmp) == -1)
			return (-1);
	}
	return (0);
}

int	ft_strcat(char **dest, char *src)
{
	char	*tmp;
    char    *freeptr;
	int		idx;
	
	tmp = malloc(ft_strlen(*dest) + ft_strlen(src) + 1);
	if (tmp == NULL)
		return (-1);
	idx = 0;
    freeptr = *dest;
    if (*dest != NULL)
	    while (**dest != 0)
	    {
	    	tmp[idx] = **dest;
            (*dest)++;
		    idx++;
	    }
	while (*src != 0)
	{
		tmp[idx] = *src;
		idx++;
		src++;
	}
	tmp[idx] = 0;
	free(freeptr);
	*dest = tmp;
	return (0);
}

int ft_strlen(char *str)
{
	int	ret;

    if (str == NULL)
        return (0);
	ret = 0;
	while (*str != 0)
	{
		str++;
		ret++;
	}
	return (ret);
}

int	newline_idx(char *str)
{
	int	ret;

	if (str == NULL)
		return (-1);
	ret = 0;
	while (*str != 0)
	{
		if (*str == '\n')
			return (ret);
		ret++;
		str++;
	}
	return (-1);
}
//
//#include <fcntl.h>
//#include <stdio.h>
//
//int main()
//{
//    int fd = open ("../test.txt",O_RDONLY);
//    char    *output;
//
//    for (int i = 0; i < 7; ++i) {
//        output = get_next_line(fd);
//        printf("output : %s\n", output);
//    }
//}