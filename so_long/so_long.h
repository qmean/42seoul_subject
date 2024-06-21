/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:26:28 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 18:43:34 by kyumkim          ###   ########.fr       */
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

typedef struct s_image
{
	void	*wall;
	void	*empty;
	void	*item;
	void	*exit;
	void	*player;
	void	*door;
	int		width;
	int		hieght;
}	t_image;

typedef struct s_game
{
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*window_ptr;
	t_image	img;
	char	**map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		coins;
	int		exit;
	int		moves;
	int		player_on_exit;
}	t_game;

void	map_error(void);
void	memory_error(void);
void	image_error(void);
void	open_error(void);
void	file_error(void);

// game_initialize
t_game	*init_game(char *input);
int		check_map_name_and_open(char *file);
int		ft_strcmp(char *str1, char *str2);
void	ft_putnbr(int num);

// image_initialize
void	init_image(t_game *game);
void	img_check(t_game *game);

// map_initialize
void	map_initialize(t_game *game, int fd);
void	put_map(t_game *game, char *line);
char	*copy_line(char	*line);

// map_size_checker.c
int		map_height(char **map);
int		map_width(char *str);

// map_error_checker.c
void	map_check(char **map);
void	check_empty_map(char **map);
void	square_check(char **map);
void	invalid_character_check(char **map);
void	no_door_check(char **map);

// map_error_checker_dfs.c
void	check_valid_path(t_game *game);
void	dfs(t_game *game, int x, int y, int **visited);
int		is_valid_position(t_game *game, int x, int y);
int		**make_visited(t_game *game);

// map_content_checker.c
void	one_player_check(char **map);
void	one_exit_check(char **map);
void	check_top_bottom_boundaries(char **map);
void	check_left_right_boundaries(char **map);
void	check_no_item(char **map);

// window_initialize.c
void	window_initialize(t_game *game);
void	put_in_map(char	*line, t_game *game, int height);

// find_player.c
void	find_player(t_game *game);
void	update_coin_num(t_game *game);
void	update_exit(t_game *game);

// exit_game.c
int		exit_game(t_game *game);
void	free_game(t_game *game);

// move.c
int		move(int key, t_game *game);
void	move_control(t_game *game, int x, int y);

#endif