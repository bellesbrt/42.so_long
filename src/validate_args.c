/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:27:05 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/25 17:49:01 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_argc(int ac)
{
	if (ac < 2)
		return (print_error (INVL_ARGS, "Try with one .ber file as argument\n"));
	if (ac > 2)
		return (print_error (INVL_ARGS, "Try only one .ber file as argument\n"));
	return (0);
}

int	validate_argv(char *av)
{
	int	fd;

	if (!ft_strrchr(av, '.'))
		return (print_error (INVL_FILE, "Try again with a .* file\n"));
	if (ft_strncmp(ft_strrchr(av, '.'), ".ber", ft_strlen(".ber")))
		return (print_error (INVL_FILE, "Try again with a .ber file\n"));
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		return (print_error (INVL_FILE, "This file is not exist\n"));
	}
	close (fd);
	return (0);
}
