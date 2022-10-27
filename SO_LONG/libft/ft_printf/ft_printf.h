/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:55:30 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/17 20:55:51 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_BASE "0123456789abcdef"

int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_int(int i);
int	ft_print_unsigned_int(unsigned int ui);
int	ft_print_pointer(void *p);
int	ft_print_hex(unsigned int ui);
int	ft_print_hex_upper(unsigned int ui);
int	ft_printf(const char *format, ...);

#endif
