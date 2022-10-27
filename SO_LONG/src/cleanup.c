/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:55:54 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 18:23:21 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_mlx(void *mlx, void *window)
{
	mlx_clear_window (mlx, window);
	mlx_destroy_window (mlx, window);
	mlx_destroy_display (mlx);
	free (mlx);
}

static void	free_images(t_game *controller)
{
	mlx_destroy_image (controller->mlx, controller->tiles.player);
	mlx_destroy_image (controller->mlx, controller->tiles.collectible);
	mlx_destroy_image (controller->mlx, controller->tiles.exit);
	mlx_destroy_image (controller->mlx, controller->tiles.floor);
	mlx_destroy_image (controller->mlx, controller->tiles.wall);
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free (matrix[i]);
	free(matrix);
}

int	cleanup(t_game *controller)
{
	free_matrix (controller->matrix);
	free_images (controller);
	free_mlx (controller->mlx, controller->window);
	ft_printf ("\n");
	exit (0);
	return (0);
}
