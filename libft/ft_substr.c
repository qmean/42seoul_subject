/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:06:24 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/26 13:14:27 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *ret;
    int     idx;

    idx = 0;
    ret = (char *)malloc(sizeof(char) * len);
    if (ret == 0)
        return (0);
    while (s[start] != 0 && len--)
    {
        ret[idx] = s[start];
        start++;
        idx++;
    }
    ret[idx] = 0;
    return (ret);
}