/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:31:30 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 18:05:19 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define INVAL_MAP "Invalid Map: "
# define CHAR "Map has an invalid char in it\n"
# define ELEMENTS "This map lack at least one mandatory element\n"
# define START_END "Only one starting/end position is accepted\n"
# define LINE_START "You should not have a new line before the map\n"
# define LINE_END "Map needs an empty line at the end\n"
# define RECTANGULAR "Map is not rectangular.\n"
# define WALL "The wall is faulty on this map.\n"
# define INVL_ARGS "Invalid number of arguments: "
# define INVL_FILE "Invalid File: "

typedef struct s_tiles
{
	void	*player;
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*wall;
}			t_tiles;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**matrix;
	int		player;
	int		collectible;
	int		moves;
	t_tiles	tiles;
}			t_game;

int		print_error(char *error, char *fix);
int		free_print_error(char *s, char *error, char *fix);
int		validate_argc(int ac);
int		validate_argv(char *av);
char	*get_all_lines(int fd, char *s);
int		validate_walls(char *map);
int		validate_map(char *map_file_location);
t_game	init_controller(char *file_path);
t_tiles	load_tiles(void *mlx);
int		cleanup(t_game *controller);
int		key_handler(int key, t_game *controller);
int		render_map(t_game *controller);
void	init_mlx(t_game *controller);

#endif
