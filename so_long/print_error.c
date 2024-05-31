/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:08:46 by kyumkim           #+#    #+#             */
/*   Updated: 2024/05/31 15:58:17 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	perror("map error");
	exit(1);
}

void	memory_error(void)
{
	perror("malloc error");
	exit(1);
}

void	image_error(void)
{
	perror("image error");
	exit(1);
}

void	open_error(void)
{
	perror("file open error");
	exit(1);
}

void	file_error(void)
{
	perror("file error");
	exit(1);
}
