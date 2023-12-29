#include "get_next_line.h"

int addfront(t_list **lst, int fd);
char    *get_next_line(int fd);
int    cutnewline(t_list *lst);
char    *makeret(char *str);
int    readfile(char **str, int fd);
int strsum(char **dest, char *src);
int ft_strlen(char *str);
int newline_idx(char *str);
char    *lastread(t_list *lst);
void ft_strdup(char *dest, char *src);

char    *get_next_line(int fd)
{
    char            *ret;
    static  t_list  *lst;
    t_list          *tmp;
    int             read_flag;

    tmp = lst;
    while(tmp != NULL)
    {
        if (tmp->fd == fd)
            break;
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
    else
        ret = makeret(lst->data);
    if (cutnewline(lst) == -1)
        return (NULL);
    return (ret);
}

char    *lastread(t_list *lst)
{
    char    *ret;

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

int    cutnewline(t_list *lst)
{
    int     lineidx;
    int     idx;
    char    *str;

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

char    *makeret(char *str)
{
    int     lineidx;
    int     idx;
    char    *ret;

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

int    readfile(char **str, int fd)
{
    int     lineidx;
    char    buffer[BUFFER_SIZE];
    int     read_size;

    lineidx = 0;
    if (*str != NULL)
        lineidx = newline_idx(*str);
    while (lineidx == 0)
    {
        read_size = read(fd ,buffer, BUFFER_SIZE - 1);
        if (read_size == -1)
            return (-1);
        else if (read_size == 0)
            return (1);
        buffer[read_size] = 0;
        lineidx = newline_idx(buffer);
        if(strsum(str, buffer) == -1)
            return (-1);
    }
    return (0);
}

void ft_strdup(char *dest, char *src)
{
    while (*src != 0)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
}

int strsum(char **dest, char *src)
{
    char    *tmp;

    if (*dest == NULL)
    {
        *dest = (char *)malloc(ft_strlen(src) + 1);
        if (*dest == NULL)
            return (-1);
        ft_strdup(*dest, src);
        return (0);
    }
    else
    {
        tmp = (char *) malloc(ft_strlen(*dest) + ft_strlen(src) + 1);
        if (tmp == NULL)
            return (-1);
    }
    ft_strdup(tmp, *dest);
    ft_strdup(tmp + ft_strlen(*dest), src);
    free(*dest);
    *dest = tmp;
    return (0);
}

int ft_strlen(char *str)
{
    int     ret;

    ret = 0;
    while (*str != 0)
    {
        str++;
        ret++;
    }
    return (ret);
}

int newline_idx(char *str)
{
    int     ret;

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

int addfront(t_list **lst, int fd)
{
    t_list  *new;
    t_list  *tmp;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (-1);
    new->data = NULL;
    new->fd = fd;
    new->next = *lst;
    new->end = 0;
    *lst = new;
    return (0);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("../test.txt",O_RDONLY);

	char *output;
    for (int i = 0; i < 7; ++i) {
        output = get_next_line(fd);
        printf("output : %s", output);
    }
	return (0);
}