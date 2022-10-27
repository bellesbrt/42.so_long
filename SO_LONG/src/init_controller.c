/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 02:03:15 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 15:53:08 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**feed_matrix(char *file_path)
{
	int		fd;
	char	*map_line;
	char	**map_matrix;

	map_line = NULL;
	fd = open (file_path, O_RDONLY);
	map_line = get_all_lines (fd, map_line);
	close (fd);
	map_matrix = ft_split(map_line, '\n');
	free (map_line);
	return (map_matrix);
}

t_game	init_controller(char *file_path)
{
	t_game	controller;
	int		l;
	int		c;

	controller.matrix = feed_matrix(file_path);
	controller.collectible = 0;
	controller.player = 0;
	controller.moves = 0;
	l = -1;
	while (controller.matrix[++l])
	{
		c = -1;
		while (controller.matrix[l][++c])
		{
			if (controller.matrix[l][c] == 'C')
				controller.collectible++;
			if (controller.matrix[l][c] == 'P')
				controller.player++;
		}
	}
	return (controller);
}
