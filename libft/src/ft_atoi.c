/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:46:53 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == ' '
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 0;
	res = 0;
	while (is_sep(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		neg = (nptr[i++] == '-');
	while (ft_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - '0');
	if (neg)
		return ((int)-res);
	return ((int)res);
}
