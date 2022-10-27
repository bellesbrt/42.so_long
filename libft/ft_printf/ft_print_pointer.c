/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:00:50 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 21:00:59 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *p)
{
	char	*s;
	int		n;

	if (!p)
		return (write(1, "(nil)", 5));
	s = ft_ultoa_base((unsigned long)p, HEXADECIMAL_BASE);
	n = write(1, "0x", 2);
	n += ft_print_string(s);
	free(s);
	return (n);
}
