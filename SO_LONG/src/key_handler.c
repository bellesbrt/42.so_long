/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:47:05 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 15:53:21 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*next_position(int key, char **matrix)
{
	int		l;
	int		c;

	l = -1;
	while (matrix[++l])
	{
		c = -1;
		while (matrix[l][++c])
		{
			if (matrix[l][c] == 'P')
			{
				if (key == 'w')
					return (&matrix[l - 1][c]);
				if (key == 's')
					return (&matrix[l + 1][c]);
				if (key == 'a')
					return (&matrix[l][c - 1]);
				if (key == 'd')
					return (&matrix[l][c + 1]);
			}
		}
	}
	return (NULL);
}

static char	*player_posioton(char **matrix)
{
	int		l;
	int		c;

	l = -1;
	while (matrix[++l])
	{
		c = -1;
		while (matrix[l][++c])
		{
			if (matrix[l][c] == 'P')
				return (&matrix[l][c]);
		}
	}
	return (NULL);
}

static int	try_move(char *p, char *np, t_game *controller)
{
	if (*np == '1')
		return (0);
	if (*np == '0')
	{
		*p = '0';
		*np = 'P';
		return (1);
	}
	if (*np == 'C')
	{
		*p = '0';
		*np = 'P';
		controller->collectible--;
		return (1);
	}
	if (*np == 'E' && controller->collectible == 0)
	{
		*p = '0';
		controller->player--;
		return (1);
	}
	return (0);
}

static void	win_condition(t_game *controller)
{
	if (!controller->player)
		cleanup (controller);
}

int	key_handler(int key, t_game *controller)
{
	char	*np;
	char	*p;

	if (key == 65307)
		cleanup(controller);
	if (ft_strchr("wasd", key))
	{
		p = player_posioton(controller->matrix);
		np = next_position(key, controller->matrix);
		controller->moves += try_move(p, np, controller);
	}
	ft_printf ("\r Moves: %d", controller->moves);
	win_condition (controller);
	return (0);
}
