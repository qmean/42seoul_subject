/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:25:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 20:39:10 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

game_t	*init_game(char *input)
{
	game_t	*ret;
	int		fd;

	ret = malloc(sizeof(game_t));
	if (ret == NULL)
		memory_error();
	ret->mlx_ptr = mlx_init();
	if (ret->mlx_ptr == NULL)
		memory_error();
	fd = check_map_name_and_open(input);
	ret->map = malloc(sizeof(char *));
	if (ret->map == NULL)
		memory_error();
	ret->map[0] = NULL;
	map_initialize(ret, fd);
	init_image(ret);
	window_initialize(ret);
	return (ret);
}

int	check_map_name_and_open(char *file)
{
	int	len;
	int	ret;

	len = ft_strlen(file);
	// TODO ft_strcmp로 변경
	if (len < 4 || strcmp(file + len - 4, ".ber") != 0)
		file_error();
	ret = open(file, O_RDONLY);
	if (ret == -1)
		open_error();
	return (ret);
}
