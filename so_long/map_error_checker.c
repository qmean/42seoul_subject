/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:52:02 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:18:17 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(char **map)
{
	check_empty_map(map);
	square_check(map);
	invalid_character_check(map);
	one_player_check(map);
	one_exit_check(map);
	no_door_check(map);
	check_top_bottom_boundaries(map);
	check_left_right_boundaries(map);
	check_no_item(map);
}

void	check_empty_map(char **map)
{
	if (map[0] == NULL)
		map_error();
}

void	square_check(char **map)
{
	int		idx;
	int		width;

	idx = 0;
	width = map_width(map[0]);
	while (map[idx] != NULL)
	{
		if (width != map_width(map[idx]))
			map_error();
		idx++;
	}
}

void	invalid_character_check(char **map)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (map[idx] != NULL)
	{
		idx2 = 0;
		while (map[idx][idx2] != '\0')
		{
			if (map[idx][idx2] != '1'
				&& map[idx][idx2] != '0'
				&& map[idx][idx2] != 'C'
				&& map[idx][idx2] != 'E'
				&& map[idx][idx2] != 'P')
				map_error();
			idx2++;
		}
		idx++;
	}
}

void	check_top_bottom_boundaries(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row] != NULL)
	{
		if (map[row][col] != '1')
			map_error();
		row++;
	}
	row--;
	while (map[row][col] != '\0')
	{
		if (map[row][col] != '1')
			map_error();
		col++;
	}
}
