/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:30:50 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/25 12:32:40 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrchr(const char *s, int c)
{
    char    *ret;

    ret  = 0;
    while (*s != 0)
    {
        if (*s == c)
            ret = s;
        s++;
    }
    return (ret);
}
