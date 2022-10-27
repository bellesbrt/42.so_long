/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:56:02 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 20:56:11 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_selector(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (*format == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (*format == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (*format == 'd' || *format == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (*format == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (*format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int)));
	if (*format == 'X')
		return (ft_print_hex_upper(va_arg(args, unsigned int)));
	if (*format == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_len;

	print_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_len += type_selector(format, args);
		}
		else
			print_len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (print_len);
}
