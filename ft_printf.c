/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/16 17:58:36 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO LEAKS WILL BE TOLERATED
#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		char_print;
	va_list	lst_args;

	char_print = 0;
	if (format == NULL)
		return (-1);
	va_start(lst_args, format);
	while (*format)
	{
		if (*format != '%')
			char_print += write(1, format, 1);
		else
		{
			++format;
			char_print += print_format(*format, lst_args);
		}
		++format;
	}
	va_end(lst_args);
	return (char_print);
}
