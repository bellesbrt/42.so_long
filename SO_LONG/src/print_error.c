/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:47:10 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/21 23:27:39 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *error, char *fix)
{
	ft_putstr_fd ("ERROR\n", 1);
	ft_putstr_fd (error, 1);
	ft_putstr_fd (fix, 1);
	return (1);
}

int	free_print_error(char *s, char *error, char *fix)
{
	free (s);
	return (print_error (error, fix));
}
