/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:53:12 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/26 13:01:20 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(const char *s1)
{
    int size;
    char    *ret;

    size = 0;
    while (s1[size] != 0)
    {
        size ++;
    }
    ret = malloc(sizeof(char) * size);
    size = 0;
    while (s1[size] != 0)
    {
        ret[size] = s1[size];
        size++;
    }
    ret[size] = 0;
    return (ret);
}