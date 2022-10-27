/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:27:09 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 22:13:34 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	new_lines(char *s)
{
	int		i;
	size_t	nl;

	i = -1;
	nl = 0;
	while (s[++i])
	{
		if (s[i] == '\n')
			nl++;
	}
	return (nl);
}

int	validate_walls(char *map)
{
	size_t	i;
	size_t	line_len;

	i = new_lines (map);
	line_len = ft_strlen(map) / i;
	i = 0;
	while (map[i])
	{
		if (map[i] != '1' || map[i + line_len - 2] != '1')
			return (1);
		i += line_len;
	}
	i = -1;
	while (map[++i] != '\n')
	{
		if (map[i] != '1')
			return (1);
	}
	i = ft_strlen(map) - line_len - 1;
	while (map[++i] != '\n')
	{
		if (map[i] != '1')
			return (1);
	}
	return (0);
}
