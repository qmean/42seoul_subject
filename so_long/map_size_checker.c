/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:17:32 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 13:29:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char **map)
{
	int		ret;

	ret = 0;
	while (map[ret] != NULL)
	{
		ret++;
	}
	return (ret);
}

int	map_width(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret] != '\0' && str[ret] != '\n')
	{
		ret++;
	}
	return (ret);
}
