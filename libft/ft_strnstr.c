/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:15:27 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/26 12:38:31 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *strnstr(const char *haystack, const char *needle, size_t len)
{
    char    *inp;
    int     idx;

    while (*haystack != 0 && len--)
    {
        inp = haystack;
        idx = 0;
        while (needle[idx] != 0)
        {
            if (needle[idx] != *inp)
                break;
            inp++;
            idx++;
        }
        if(needle[idx] == 0)
            return (haystack);
        haystack++;
    }
    return (0);
}