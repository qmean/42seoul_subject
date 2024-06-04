/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check_dfs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:26:46 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 16:55:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_position(t_game *game, int x, int y)
{
	if (x >= 0 && x < game->width && y >= 0 && y < game->height)
	{
		if (game->map[y][x] != WALL)
			return (1);
	}
	return (0);
}

void	dfs(t_game *game, int x, int y, int **visited)
{
	if (!is_valid_position(game, x, y) || visited[y][x])
		return ;
	visited[y][x] = 1;
	if (game->map[y][x] == ITEM)
		game->coins--;
	if (game->map[y][x] == EXIT)
		game->exit--;
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
}

void	check_valid_path(t_game *game)
{
	int	**visited;
	int	i;

	visited = make_visited(game);
	dfs(game, game->player_x, game->player_y, visited);
	if (game->coins != 0 || game->exit != 0)
		map_error();
	i = 0;
	while (i < game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	update_coin_num(game);
	update_exit(game);
	game->exit = 1;
}

int	**make_visited(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	visited = (int **)malloc(game->height * sizeof(int *));
	if (visited == NULL)
		memory_error();
	i = 0;
	while (i < game->height)
	{
		visited[i] = (int *)malloc(game->width * sizeof(int));
		if (visited[i] == NULL)
			memory_error();
		j = 0;
		while (j < game->width)
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}
