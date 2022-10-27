/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:47:13 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 15:53:37 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *controller, void *img, int l, int c)
{
	l *= 32;
	c *= 32;
	mlx_put_image_to_window(controller->mlx, controller->window, img, c, l);
}

int	render_map(t_game *controller)
{
	int	l;
	int	c;

	l = -1;
	while (controller->matrix[++l])
	{
		c = -1;
		while (controller->matrix[l][++c])
		{
			if (controller->matrix[l][c] == '1')
				put_image(controller, controller->tiles.wall, l, c);
			if (controller->matrix[l][c] == '0')
				put_image(controller, controller->tiles.floor, l, c);
			if (controller->matrix[l][c] == 'P')
				put_image(controller, controller->tiles.player, l, c);
			if (controller->matrix[l][c] == 'C')
				put_image(controller, controller->tiles.collectible, l, c);
			if (controller->matrix[l][c] == 'E')
				put_image(controller, controller->tiles.exit, l, c);
		}
	}
	return (0);
}
