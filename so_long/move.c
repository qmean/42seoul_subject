/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:50:55 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 20:41:09 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key, game_t *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (key == UP)
		y--;
	else if (key == DOWN)
		y++;
	else if (key == LEFT)
		x--;
	else if (key == RIGHT)
		x++;
	else if (key == ESC)
		exit_game(game);
	move_control(game, x, y);
	y = 0;
	while (y != game->height)
	{
		put_in_map(game->map[y], game, y);
		y++;
	}
	return (0);
}

void	move_control(game_t *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		return ;
	if (game->map[y][x] == ITEM)
	{
		game->coins--;
		if (game->coins == 0)
			game->map[game->exit_y][game->exit_x] = DOOR;
	}
	if (game->map[y][x] == EXIT && game->coins == 0)
	{
		exit_game(game);
	}
	game->map[game->player_y][game->player_x] = EMPTY;
	game->map[y][x] = PLAYER;
	game->player_x = x;
	game->player_y = y;
	game->moves++;
}
