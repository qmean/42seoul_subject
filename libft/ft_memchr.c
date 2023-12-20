/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:05:21 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/26 12:09:39 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *memchr(const void *s, int c, size_t n)
{
    unsigned char   *inp;

    inp = s;
    while (*inp != 0 && n--)
    {
        if (*inp == c)
        {
            return (inp);
        }
        inp++;
    }
    return (0);
}
