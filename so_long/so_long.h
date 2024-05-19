/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:26:28 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/19 18:22:32 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "stdlib.h"
# include "printf.h"
# include "fcntl.h"
# include "get_next_line/get_next_line.h"

# define EXIT_IMG = "/image/exit.xpm"
# define FLOOR_IMG = "/image/floog.xpm"
# define ITEM_IMG = "/image/item.xpm"
# define PLAYER_IMG = "/image/player.xpm"
# define WALL_IMG = "/image/wall.xpm"

struct so_long
{
	int	height;
	int	width;
}typedef so_long_t;


#endif