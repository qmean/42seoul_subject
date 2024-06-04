/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:25:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:21:59 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(char *input)
{
	t_game	*ret;
	int		fd;

	ret = malloc(sizeof(t_game));
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
	if (len < 4 || ft_strcmp(file + len - 4, ".ber") != 0)
		file_error();
	ret = open(file, O_RDONLY);
	if (ret == -1)
		open_error();
	return (ret);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
