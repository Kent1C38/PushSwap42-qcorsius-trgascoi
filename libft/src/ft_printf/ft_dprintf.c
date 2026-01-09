/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/09 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "../includes/ft_printf.h"

static int	ft_putchar_fd2(char c, int fd, int *total)
{
	int	result;

	result = write(fd, &c, 1);
	if (result != -1)
		*total = *total + 1;
	return (result);
}

static int	ft_putstr_fd2(char *str, int fd, int *total)
{
	int	i;
	int	last_written;

	if (str == NULL)
		str = "(null)";
	i = -1;
	last_written = 0;
	while (str[++i])
	{
		last_written = ft_putchar_fd2(str[i], fd, total);
		if (last_written == -1)
			break ;
	}
	return (last_written);
}

static int	put_integer_fd(long number, int fd, int *total)
{
	int	last_written;

	if (number < 0)
	{
		last_written = ft_putchar_fd2('-', fd, total);
		if (last_written == -1)
			return (-1);
		return (put_integer_fd(-number, fd, total));
	}
	if (number >= 10)
	{
		last_written = put_integer_fd(number / 10, fd, total);
		if (last_written == -1)
			return (-1);
	}
	return (ft_putchar_fd2(number % 10 + '0', fd, total));
}

static int	handle_format(char c, va_list args, int fd, int *count)
{
	if (c == 'd' || c == 'i')
		return (put_integer_fd(va_arg(args, int), fd, count));
	else if (c == 's')
		return (ft_putstr_fd2(va_arg(args, char *), fd, count));
	else if (c == '%')
		return (ft_putchar_fd2('%', fd, count));
	return (0);
}

int	ft_dprintf(int fd, const char *str, ...)
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
			handle_format(str[i++], args, fd, &char_count);
		}
		else
			ft_putchar_fd2(str[i++], fd, &char_count);
	}
	va_end(args);
	return (char_count);
}
