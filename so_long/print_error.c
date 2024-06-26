/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:08:46 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/04 20:04:48 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	write(2, "Error\n", 6);
	write(2, "map error\n", 10);
	exit(EXIT_FAILURE);
}

void	memory_error(void)
{
	write(2, "Error\n", 6);
	write(2, "malloc error\n", 13);
	exit(EXIT_FAILURE);
}

void	image_error(void)
{
	write(2, "Error\n", 6);
	write(2, "image error\n", 12);
	exit(EXIT_FAILURE);
}

void	open_error(void)
{
	write(2, "Error\n", 6);
	write(2, "file open error\n", 16);
	exit(EXIT_FAILURE);
}

void	file_error(void)
{
	write(2, "Error\n", 6);
	write(2, "file error\n", 11);
	exit(EXIT_FAILURE);
}
