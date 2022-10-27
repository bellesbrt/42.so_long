/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:01:07 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 22:26:48 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int ui)
{
	char	*s;
	int		n;

	s = ft_ultoa_base((unsigned long)ui, HEXADECIMAL_BASE);
	n = ft_print_string(s);
	free(s);
	return (n);
}
