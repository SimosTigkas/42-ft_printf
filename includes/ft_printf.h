/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:31:47 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/21 09:15:32 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		pr_format(char spec, va_list lst_args);
int		print_hex(unsigned long n, char spec);
int		print_u(unsigned int n);
int		print_ptr(unsigned long ptr);
int		h(int char_print, int w);

#endif