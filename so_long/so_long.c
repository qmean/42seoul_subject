/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:59 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:43:57 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	atexit(leaks);
	if (argc != 2)
		return (1);
	game = init_game(argv[1]);
	game->player_on_exit = 0;
	mlx_key_hook(game->window_ptr, move, game);
	mlx_hook(game->window_ptr, 17, 0, exit_game, game);
	mlx_loop(game->mlx_ptr);
}
