/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/20 14:24:44 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NO LEAKS WILL BE TOLERATED
#include "includes/ft_printf.h"
#include <limits.h>

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
//     ft_printf("Ours:%u", -200000);
// 	printf("Normal: %u", -200000);
// 	return (0);
// }