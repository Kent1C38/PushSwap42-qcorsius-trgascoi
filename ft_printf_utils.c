/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:18:12 by qcorsius          #+#    #+#             */
/*   Updated: 2025/12/12 12:30:05 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	ft_putchar(char c, int *total)
{
	int	result;

	result = write(1, &c, 1);
	if (result != -1)
		*total = *total + 1;
	return (result);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str, int *total)
{
	int	i;
	int	last_written;

	if (str == NULL)
		return (ft_putstr("(null)", total));
	i = -1;
	last_written = 0;
	while (str[++i])
	{
		last_written = ft_putchar(str[i], total);
		if (last_written == -1)
			break ;
	}
	return (last_written);
}

int	put_integer(long number, int *total)
{
	int	last_written;

	if (number < 0)
	{
		last_written = ft_putchar('-', total);
		number = -number;
	}
	if (number < 10)
		last_written = ft_putchar(number + '0', total);
	else
	{
		last_written = put_integer(number / 10, total);
		if (last_written == -1)
			return (-1);
		last_written = put_integer(number % 10, total);
	}
	return (last_written);
}

int	put_nb_base(unsigned long number, char *base, int *total)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (number < base_len)
		return (ft_putchar(base[number], total));
	if (put_nb_base(number / base_len, base, total) == -1)
		return (-1);
	return (put_nb_base(number % base_len, base, total));
}
