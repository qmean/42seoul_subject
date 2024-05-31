/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:11:20 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 18:02:17 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_initialize(game_t *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		put_map(game, line);
		line = get_next_line(fd);
	}
	map_check(game->map);
	game->height = map_height(game->map);
	game->width = map_width(game->map[0]);
	update_coin_num(game);
	game->exit = 1;
	find_player(game);
	check_valid_path(game);
}

void	put_map(game_t *game, char *line)
{
	char	**tmp;
	int		idx;

	tmp = malloc(sizeof(char *) * (map_height(game->map) + 2));
	if (tmp == NULL)
		memory_error();
	idx = 0;
	while ((game->map)[idx] != NULL)
	{
		tmp[idx] = (game->map)[idx];
		idx++;
	}
	tmp[idx++] = copy_line(line);
	tmp[idx] = NULL;
	free(game->map);
	game->map = tmp;
}

char	*copy_line(char	*line)
{
	int		idx;
	char	*ret;

	ret = malloc(sizeof(char) * (map_width(line)));
	if (ret == NULL)
		memory_error();
	idx = 0;
	while (line[idx] != '\0' && line[idx] != '\n')
	{
		ret[idx] = line[idx];
		idx++;
	}
	ret[idx] = '\0';
	free(line);
	return (ret);
}
