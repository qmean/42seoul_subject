/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:04:13 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 13:27:57 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(game_t *game)
{
	image_t	*image;

	image = &game->img;
	image->empty = mlx_xpm_file_to_image
		(game->mlx_ptr, "./image/floor.xpm", &image->width, &image->hieght);
	image->exit = mlx_xpm_file_to_image
		(game->mlx_ptr, "./image/exit.xpm", &image->width, &image->hieght);
	image->item = mlx_xpm_file_to_image
		(game->mlx_ptr, "./image/item.xpm", &image->width, &image->hieght);
	image->player = mlx_xpm_file_to_image
		(game->mlx_ptr, "./image/player.xpm", &image->width, &image->hieght);
	image->wall = mlx_xpm_file_to_image
		(game->mlx_ptr, "./image/wall.xpm", &image->width, &image->hieght);
	img_check(game);
}

void	img_check(game_t *game)
{
	if (game->img.wall == NULL)
		exit(1);
	else if (game->img.empty == NULL)
		exit(1);
	else if (game->img.item == NULL)
		exit(1);
	else if (game->img.exit == NULL)
		exit(1);
	else if (game->img.player == NULL)
		exit(1);
}
