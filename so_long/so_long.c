/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:59 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/19 18:25:36 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr = mlx_init();
	void	*window_ptr = mlx_new_window(mlx_ptr, 3, 3, "window");
	so_long_t	*game = malloc(sizeof(so_long_t));
	if (argc < 2)
		return (0);
	map_read(argv[1], game);
	mlx_loop(mlx_ptr);
}

void	map_read(char *filename, so_long_t *game)
{
	int 	fd;
	char	*line;

	fd  = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;

}