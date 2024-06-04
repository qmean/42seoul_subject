/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:50:55 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 19:17:16 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key, t_game *game)
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

void	move_control(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		return ;
	if (game->map[y][x] == ITEM)
	{
		game->coins--;
		if (game->coins == 0)
			game->map[game->exit_y][game->exit_x] = DOOR;
	}
	if (game->map[y][x] == DOOR && game->coins == 0)
		exit_game(game);
	if (game->player_x == game->exit_x && game->player_y == game->exit_y
		&& game->coins != 0)
	{
		game->map[game->player_y][game->player_x] = EXIT;
		game->player_on_exit = 0;
	}
	else
		game->map[game->player_y][game->player_x] = EMPTY;
	game->map[y][x] = PLAYER;
	game->player_x = x;
	game->player_y = y;
	game->moves++;
	ft_putnbr(game->moves);
	write(1, "\n", 1);
}

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}
