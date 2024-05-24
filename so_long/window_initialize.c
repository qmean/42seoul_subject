/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:28:03 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/24 20:05:20 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	window_initialize(game_t *game)
{
	char	**map;
	int		x;
	int		y;

	game->window_ptr = mlx_new_window(game->mlx_ptr, game->width * game->img.width,
		game->height * game->img.hieght, "so_long");
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

void	put_in_map(char	*line, game_t *game, int y)
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
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			img_ptr, game->img.width * width, game->img.hieght * y);
		width++;
	}
}