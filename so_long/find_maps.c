/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:41:29 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:18:32 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int		idx;
	int		jdx;

	idx = 0;
	while (game->map[idx] != NULL)
	{
		jdx = 0;
		while (game->map[idx][jdx] != '\0')
		{
			if (game->map[idx][jdx] == PLAYER)
			{
				game->player_x = jdx;
				game->player_y = idx;
				return ;
			}
			jdx++;
		}
		idx++;
	}
	map_error();
}

void	update_coin_num(t_game *game)
{
	int		idx;
	int		jdx;

	idx = 0;
	game->coins = 0;
	while (game->map[idx] != NULL)
	{
		jdx = 0;
		while (game->map[idx][jdx] != '\0')
		{
			if (game->map[idx][jdx] == ITEM)
				game->coins++;
			jdx++;
		}
		idx++;
	}
}

void	update_exit(t_game *game)
{
	int		idx;
	int		jdx;

	idx = 0;
	while (game->map[idx] != NULL)
	{
		jdx = 0;
		while (game->map[idx][jdx] != '\0')
		{
			if (game->map[idx][jdx] == EXIT)
			{
				game->exit_x = jdx;
				game->exit_y = idx;
				return ;
			}
			jdx++;
		}
		idx++;
	}
	map_error();
}
