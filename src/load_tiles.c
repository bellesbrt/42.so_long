/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:47:07 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 16:00:36 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_sprite(void *mlx, char *file_path)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	return (mlx_xpm_file_to_image(mlx, file_path, &x, &y));
}

t_tiles	load_tiles(void *mlx)
{
	t_tiles	tiles;

	tiles.player = get_sprite(mlx, "imgs/player.xpm");
	tiles.collectible = get_sprite(mlx, "imgs/collectible.xpm");
	tiles.exit = get_sprite(mlx, "imgs/exit.xpm");
	tiles.floor = get_sprite(mlx, "imgs/floor.xpm");
	tiles.wall = get_sprite(mlx, "imgs/wall.xpm");
	return (tiles);
}
