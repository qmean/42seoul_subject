/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:26:28 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 19:59:47 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
# include "get_next_line/get_next_line.h"

# include "string.h"

# define WALL '1'
# define EMPTY '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define DOOR 'D'

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

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
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		coins;
	int		exit;
	int		moves;
}typedef	game_t;

void	map_error(void);
void	memory_error(void);
void	image_error(void);
void	open_error(void);
void	file_error(void);

// game_initialize
game_t	*init_game(char *input);
int		check_map_name_and_open(char *file);

// image_initialize
void	init_image(game_t *game);
void	img_check(game_t *game);

// map_initialize
void	map_initialize(game_t *game, int fd);
void	put_map(game_t *game, char *line);
char	*copy_line(char	*line);

// map_size_checker.c
int		map_height(char **map);
int		map_width(char *str);

// map_error_checker.c
void	map_check(char **map);
void	check_empty_map(char **map);
void	square_check(char **map);
void	invalid_character_check(char **map);

// map_error_checker_dfs.c
void	check_valid_path(game_t *game);
void	dfs(game_t *game, int x, int y, int **visited);
int		is_valid_position(game_t *game, int x, int y);
int		**make_visited(game_t *game);

// map_content_checker.c
void	one_player_check(char **map);
void	one_exit_check(char **map);
void	check_top_bottom_boundaries(char **map);
void	check_left_right_boundaries(char **map);
void	check_no_item(char **map);

// window_initialize.c
void	window_initialize(game_t *game);
void	put_in_map(char	*line, game_t *game, int height);

// find_player.c
void	find_player(game_t *game);
void	update_coin_num(game_t *game);
void	update_exit(game_t *game);

// exit_game.c
int		exit_game(game_t *game);
void	free_game(game_t *game);

// move.c
int		move(int key, game_t *game);
void	move_control(game_t *game, int x, int y);

#endif