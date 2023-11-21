/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/21 11:31:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	h(int char_print, int w)
{
	if (char_print < 0 || w < 0)
		return (-1);
	else
		return (char_print + w);
}

int	ft_printf(const char *format, ...)
{
	int		char_print;
	va_list	lst_args;

	char_print = 0;
	va_start(lst_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			char_print = h(char_print, write(1, format, 1));
			if (char_print == -1)
				return (-1);
		}
		else
		{
			char_print = h(char_print, pr_format(*(++format), lst_args));
			if (char_print == -1)
				return (-1);
		}
		format++;
	}
	va_end(lst_args);
	return (char_print);
}
