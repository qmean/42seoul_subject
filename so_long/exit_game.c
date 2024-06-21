/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:58:08 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 16:55:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.empty);
	mlx_destroy_image(game->mlx_ptr, game->img.item);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.player);
	mlx_clear_window(game->mlx_ptr, game->window_ptr);
	mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	free_game(game);
	exit(0);
}

void	free_game(t_game *game)
{
	int	idx;

	idx = 0;
	while (game->map[idx] != NULL)
	{
		free(game->map[idx]);
		idx++;
	}
	free(game->map[idx]);
	free(game->map);
	free(game);
}
