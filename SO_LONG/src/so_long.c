/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:07:09 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 15:53:46 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	controller;

	if (validate_argc(argc))
		return (1);
	if (validate_argv(argv[1]))
		return (1);
	if (validate_map(argv[1]))
		return (1);
	controller = init_controller(argv[1]);
	init_mlx(&controller);
	return (0);
}
