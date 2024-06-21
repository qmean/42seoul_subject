/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:28:03 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:37:19 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_initialize(t_game *game)
{
	char	**map;
	int		map_size;
	int		x;
	int		y;

	map_size = game->width * game->img.width;
	game->window_ptr = mlx_new_window(game->mlx_ptr,
			map_size, game->height * game->img.hieght, "game");
	if (game->window_ptr == NULL)
		memory_error();
	map = game->map;
	x = 0;
	y = 0;
	while (y != game->height)
	{
		put_in_map(map[y], game, y);
		y++;
	}
}

void	put_in_map(char	*line, t_game *game, int y)
{
	int		width;
	void	*img_ptr;

	width = 0;
	while (line[width] != '\0' && line[width] != '\n')
	{
		if (line[width] == WALL)
			img_ptr = game->img.wall;
		else if (line[width] == EMPTY)
			img_ptr = game->img.empty;
		else if (line[width] == ITEM)
			img_ptr = game->img.item;
		else if (line[width] == EXIT)
			img_ptr = game->img.exit;
		else if (line[width] == PLAYER)
			img_ptr = game->img.player;
		else if (line[width] == DOOR)
			img_ptr = game->img.door;
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			img_ptr, game->img.width * width, game->img.hieght * y);
		width++;
	}
}
