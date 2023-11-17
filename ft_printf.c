/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/17 13:31:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO LEAKS WILL BE TOLERATED
#include "includes/ft_printf.h"
#include <limits.h>

int	h_w_e(int char_print)
{
	if (char_print < 0)
		return (-1);
	return (char_print);
}

int	ft_printf(const char *format, ...)
{
	int		char_print;
	va_list	lst_args;
	int		e;

	char_print = 0;
	if (format == NULL)
		return (-1);
	va_start(lst_args, format);
	while (*format)
	{
		e = char_print;
		if (*format != '%')
			char_print = h_w_e(char_print + write(1, format, 1));
		else
		{
			++format;
			char_print = h_w_e(char_print + print_format(*format, lst_args));
		}
		if (e > char_print)
			return (-1);
		format++;
	}
	va_end(lst_args);
	return (char_print);
}

// print(" %p %p ", LONG_MIN, LONG_MAX));
// 32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// int	main(void)
// {
// 	printf("Normal: \001\002\007\v\010\f\r\n");
// 	ft_printf("Ours \001\002\007\v\010\f\r\n");
// 	return (0);
// }

// int	main(void)
// {
// 	ft_printf("%p\n", "");
// 	printf("%p\n", "");
//     return (0);
// }