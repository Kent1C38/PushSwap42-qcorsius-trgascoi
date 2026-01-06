/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:47:01 by qcorsius          #+#    #+#             */
/*   Updated: 2025/12/12 12:34:36 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "../includes/ft_printf.h"

int	pointer_handling(void *arg, int *total)
{
	if (arg == 0)
		return (ft_putstr("(nil)", total));
	if (ft_putstr("0x", total) == -1)
		return (-1);
	return (put_nb_base((uintptr_t)arg, "0123456789abcdef", total));
}

int	handle_placeholder(char c, va_list args, int *total)
{
	if (c == '%')
		return (ft_putchar('%', total));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int), total));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), total));
	else if (c == 'i' || c == 'd')
		return (put_integer(va_arg(args, int), total));
	else if (c == 'u')
		return (put_integer(va_arg(args, unsigned int), total));
	else if (c == 'x')
		return (put_nb_base(va_arg(args, unsigned int),
				"0123456789abcdef", total));
	else if (c == 'X')
		return (put_nb_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", total));
	else if (c == 'p')
		return (pointer_handling(va_arg(args, void *), total));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		char_count;
	va_list	args;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	i = 0;
	char_count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (handle_placeholder(str[i++], args, &char_count) == -1)
				return (-1);
		}
		else
			if (ft_putchar(str[i++], &char_count) == -1)
				return (-1);
	}
	va_end(args);
	return (char_count);
}
