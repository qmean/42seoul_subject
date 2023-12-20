/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:09:56 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/26 12:14:52 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char   *inp1;
    unsigned char   *inp2;

    inp1 = s1;
    inp2 = s2;

    while (*inp1 != 0 && *inp2 != 0 && n--)
    {
        if (*inp1 != inp2)
        {
            return (*inp1 - *inp2);
        }
        inp1++;
        inp2++;
    }
    return (0);
}