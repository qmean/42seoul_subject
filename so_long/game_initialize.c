/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   game_initialize.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: kyumkim <kyumkim@student.42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/05/24 18:55:21 by kyumkim   #+##+# */
/*   Updated: 2024/05/24 19:06:56 by kyumkim  ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "so_long.h"

game_t  *init_game(char *input)
{
	game_t  *ret;
	int		fd;

	ret = malloc(sizeof(game_t));
	if (ret == NULL)
		memory_error();
	ret->mlx_ptr = mlx_init();
	if (ret->mlx_ptr == NULL)
		memory_error();
	fd = open(input, O_RDONLY);
	if (fd < 0)
		open_error();
	ret->map = malloc(sizeof(char *));
	if (ret->map == NULL)
		memory_error();
	ret->map[0] = NULL;
	map_initialize(ret, fd);
	init_image(ret);
	window_initialize(ret);
	return (ret);
}
