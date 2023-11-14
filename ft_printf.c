/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/14 17:19:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO LEAKS WILL BE TOLERATED
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		char_print;
	va_list	lst_args;
	char	c;

	char_print = 0;
	if (format == NULL)
		return (-1);
	va_start(lst_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		format++;
		/*else
		{
			format++;
			if (*format == '\0')
				break ;
			if (*format == '%')
			{
				ft_putchar(format);
				char_print++;
			}
			else if (*format == 'c')
			{
				c = 
			}
			write(1, num, ft_strlen(num));
			va_end(lst_args);
		}*/
		va_end(lst_args);
	}
	return (char_print);
}

int	main(void)
{
	ft_printf("String\n");
	return (0);
}
