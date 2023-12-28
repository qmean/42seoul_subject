/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:43:30 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/22 17:41:12 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	ft_lst_addback(t_list **list, t_list *new);
int	read_fd(int fd, t_list **list);
char	*cut_string(t_list *lst);
char	*sum_string(t_list *start, t_list *end);
int	cal_len(t_list *start, t_list *end);
size_t	ft_strlen(char *str);
void    clear_lst(t_list *start, t_list *end);
int	check_nextline(t_list *lst);

int	read_fd(int fd, t_list **list)
{
	int		read_size;
	t_list	*tmp;

	if (fd < 0)
		return (-1);
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
	{
		// malloc 실패시 전부 삭제하는 함수 구현
		return (-1);
	}
	read_size = read(fd, tmp->data, BUFFER_SIZE - 1);
	if (read_size <= 0)
		return (-1);
	tmp->data[read_size] = 0;
	ft_lst_addback(list, tmp);
	return (read_size);
}

void	ft_lst_addback(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	return ;
}

// 개행 만날때까지의 string 을 다 합치고 합친 나머지를 따로 리스트로 잘라서 빼는 함수
char	*cut_string(t_list *lst)
{
	int		nextline;
    char    *ret;
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		nextline = check_nextline(lst);
		if (nextline)
			break ;
		tmp = tmp->next;
	}
    ret = sum_string(lst, tmp);
    clear_lst(lst,tmp);
	return (ret);
}

// 개행을 만날 때까지 리스트를 삭제하는 연산
void    clear_lst(t_list *start, t_list *end)
{
    t_list *tmp;
    char   *str;
    int     idx;

    tmp = start;
    start = start->next;
    while(tmp != end)
    {
        free(tmp->data);
        free(tmp);
        tmp = start;
        start = start->next;
    }
    str = tmp->data;
    while (*str != '\n')
        str++;
    str++;
    idx = 0;
    while (*str != '\0')
    {
        tmp->data[idx] = *str;
        str++;
    }
    tmp->data[idx] = 0;
}

// start 부터 end 까지의 데이터를 다 합치는 함수
char	*sum_string(t_list *start, t_list *end)
{
	char	*ret;
	char	*tmp;
	int		idx;

	idx = 0;
	ret = malloc(sizeof(char) * cal_len(start, end));
	while (start != end)
	{
		tmp = start->data;
		while (*tmp != 0)
			ret[idx++] = *tmp++;
		start = start->next;
	}
	tmp = end->data;
	while (*tmp != '\n')
		ret[idx++] = *tmp++;
    ret[idx++] = '\n';
    ret[idx] = '\0';
	return (ret);
}

// 리턴해야 할 총 문자열 길이를 계산하는 함수(malloc 하기 위해)
int	cal_len(t_list *start, t_list *end)
{
	int		ret;
	char	*tmp;

	ret = 0;
	while (start != end)
	{
		ret = ret + ft_strlen(start->data);
		start = start->next;
	}
	tmp = start->data;
	while (*tmp != '\n' && *tmp != '\0')
	{
		ret++;
		tmp++;
	}
	return (ret + 2);
}

// strlen
size_t	ft_strlen(char *str)
{
	size_t	ret;

	ret = 0;
	while (*str != '\0')
	{
		ret++;
		str++;
	}
	return (ret);
}
// 개행이 몇개인지 리턴하는 함수
int	check_nextline(t_list *lst)
{
	char	*buf;
	int		cnt;

	cnt = 0;
	buf = lst->data;
	while (*buf != '\0')
	{
		if (*buf == '\n')
			cnt++;
		buf++;
	}
	return (cnt);
}
// 원본 함수
char	*get_next_line(int fd)
{
	int				read_size;
	static t_list	*list;

	read_size = read_fd(fd, &list);
	while (read_size > 0)
	{
		read_size = read_fd(fd, &list);
	}
    return (cut_string(list));
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("../test.txt",O_RDONLY);

    perror("error : ");
	char *output = get_next_line(fd);
	printf("output : %s", output);
    output = get_next_line(fd);
    printf("output : %s", output);
	return (0);
}