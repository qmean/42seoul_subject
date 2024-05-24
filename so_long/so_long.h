/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:26:28 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/24 20:18:54 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
# include "get_next_line/get_next_line.h"

# define WALL '1'
# define EMPTY '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'

struct image_s
{
	void	*wall;
	void	*empty;
	void	*item;
	void	*exit;
	void	*player;
	int		width;
	int		hieght;
}typedef	image_t;

struct game_s
{
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*window_ptr;
	image_t	img;
	char	**map;
}typedef	game_t;

void	map_error(void);
void	memory_error(void);
void	image_error(void);
void	open_error(void);

// game_initialize
game_t  *init_game(char *input);

// image_initialize
void	init_image(game_t *game);
void	img_check(game_t *game);

// map_initialize
void    map_initialize(game_t *game, int fd);
void    put_map(game_t *game, char *line);
char	*copy_line(char	*line);

// map_size_checker.c
int map_height(char **map);
int map_width(char *str);

// map_error_checker.c
void    map_check(char  **map);

// window_initialize.c
void	window_initialize(game_t *game);
void	put_in_map(char	*line, game_t *game, int height);
#endif