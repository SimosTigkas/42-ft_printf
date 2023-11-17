/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:31:47 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/17 09:01:08 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_format(char spec, va_list lst_args);
int		print_hex(unsigned long n, char spec);
int		print_u(unsigned int n);
int		print_ptr(unsigned long n);
int		print_dec(long long n);

#endif