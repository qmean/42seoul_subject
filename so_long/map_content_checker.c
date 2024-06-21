/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:38:22 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:34:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	one_player_check(char **map)
{
	int	player_count;
	int	idx;
	int	idx2;

	player_count = 0;
	idx = 0;
	while (map[idx] != NULL)
	{
		idx2 = 0;
		while (map[idx][idx2] != '\0')
		{
			if (map[idx][idx2] == 'P')
			{
				player_count++;
				if (player_count > 1)
					map_error();
			}
			idx2++;
		}
		idx++;
	}
	if (player_count == 0)
		map_error();
}

void	no_door_check(char **map)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (map[idx] != NULL)
	{
		idx2 = 0;
		while (map[idx][idx2] != '\0')
		{
			if (map[idx][idx2] == 'D')
				map_error();
			idx2++;
		}
		idx++;
	}
	return ;
}

void	one_exit_check(char **map)
{
	int	exit_count;
	int	idx;
	int	idx2;

	exit_count = 0;
	idx = 0;
	while (map[idx] != NULL)
	{
		idx2 = 0;
		while (map[idx][idx2] != '\0')
		{
			if (map[idx][idx2] == 'E')
			{
				exit_count++;
				if (exit_count > 1)
					map_error();
			}
			idx2++;
		}
		idx++;
	}
	if (exit_count == 0)
		map_error();
}

void	check_left_right_boundaries(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row] != NULL)
	{
		if (map[row][col] != '1')
			map_error();
		col = ft_strlen(map[row]) - 1;
		if (map[row][col] != '1')
			map_error();
		row++;
	}
}

void	check_no_item(char **map)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (map[idx] != NULL)
	{
		idx2 = 0;
		while (map[idx][idx2] != '\0')
		{
			if (map[idx][idx2] == 'C')
				return ;
			idx2++;
		}
		idx++;
	}
	map_error();
}
