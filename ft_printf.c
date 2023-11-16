/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/16 12:27:07 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO LEAKS WILL BE TOLERATED
#include "ft_printf.h"
#include <limits.h>

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

int	main(void)
{
	int	count;
	long int num = 10;
    void *ptr;

	ptr = &num;
	count = ft_printf("%u\n", INT_MAX + 1);
	ft_printf("The chars written are %i\n", count);
	count = printf("%u\n", INT_MAX + 1);
	printf("The chars written are %i\n", count);
	count = ft_printf("%d\n", 052);
	ft_printf("The chars written are %d\n", count);
	count = printf("%d\n", 052);
	printf("The chars written are %d\n", count);
	ft_printf("Hello %s, today is %i, in hex %X, char -> %c\n",
				"Simos",
				 15,
				  15,
				   's');
	ft_printf("%%\n");
    printf("Address of num: %p\n", ptr);
    ft_printf("Address of num: %p\n", ptr);
	return (0);
}