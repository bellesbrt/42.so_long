/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:25:25 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 22:25:27 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int ui)
{
	char	*s;
	int		n;

	s = ft_ultoa_base((unsigned long)ui, DECIMAL_BASE);
	n = ft_print_string(s);
	free(s);
	return (n);
}
