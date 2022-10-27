/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:27:02 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 18:19:50 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_shape(char *map_line)
{
	int	i;
	int	line[2];

	i = 0;
	while (map_line[i] && map_line[i] != '\n')
		i++;
	line[0] = i;
	while (map_line[++i])
	{
		if (map_line[i] == '\n')
		{
			line[1] = i - 1;
			while (map_line[line[1]] && map_line[line[1]] != '\n')
				line[1]--;
			line[1] = i - (line[1] + 1);
			if (line[0] != line[1])
				return (1);
		}
	}
	return (0);
}

static int	validate_elements(char *map_line)
{
	int	elements[4];

	elements[0] = -1;
	elements[1] = 0;
	elements[2] = 0;
	elements[3] = 0;
	while (map_line[++elements[0]])
	{
		if (map_line[elements[0]] == 'P')
			++elements[1];
		if (map_line[elements[0]] == 'C')
			++elements[2];
		if (map_line[elements[0]] == 'E')
			++elements[3];
	}
	if (elements[1] == 0 || elements[2] == 0 || elements[3] == 0)
		return (1);
	if (elements[1] != 1)
		return (2);
	if (elements[3] != 1)
		return (2);
	return (0);
}

static int	validate_chars(char *map_line)
{
	int	i;

	i = -1;
	while (map_line[++i])
	{
		if (!ft_strchr("10PCE\n", map_line[i]))
			return (1);
	}
	return (0);
}

int	validate_map(char *map_file_location)
{
	int		fd;
	char	*map_line;

	map_line = NULL;
	fd = open (map_file_location, O_RDONLY);
	map_line = get_all_lines (fd, map_line);
	close (fd);
	if (validate_chars(map_line))
		return (free_print_error(map_line, INVAL_MAP, CHAR));
	if (validate_elements(map_line) == 1)
		return (free_print_error(map_line, INVAL_MAP, ELEMENTS));
	if (validate_elements(map_line) == 2)
		return (free_print_error(map_line, INVAL_MAP, START_END));
	if (map_line[0] == '\n')
		return (free_print_error(map_line, INVAL_MAP, LINE_START));
	if (map_line[ft_strlen(map_line) - 1] != '\n')
		return (free_print_error(map_line, INVAL_MAP, LINE_END));
	if (validate_shape(map_line))
		return (free_print_error(map_line, INVAL_MAP, RECTANGULAR));
	if (validate_walls(map_line))
		return (free_print_error(map_line, INVAL_MAP, WALL));
	free (map_line);
	return (0);
}
