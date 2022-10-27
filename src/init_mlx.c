/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:47:01 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 15:52:53 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*init_window(t_game *controller)
{
	int	x;
	int	y;

	y = 0;
	while (controller->matrix[y])
		y++;
	x = 0;
	while (controller->matrix[0][x])
		x++;
	x *= 32;
	y *= 32;
	controller->window = mlx_new_window(controller->mlx, x, y, "SO_LONG");
	return (controller->window);
}

void	init_mlx(t_game *controller)
{
	controller->mlx = mlx_init();
	controller->tiles = load_tiles (controller->mlx);
	controller->window = init_window (controller);
	ft_printf ("\r Moves: %d", controller->moves);
	mlx_loop_hook (controller->mlx, render_map, controller);
	mlx_key_hook (controller->window, key_handler, controller);
	mlx_hook (controller->window, 17, 0, cleanup, controller);
	mlx_loop (controller->mlx);
}
