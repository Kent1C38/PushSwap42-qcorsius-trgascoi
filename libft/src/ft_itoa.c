/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:45:09 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	needed_chars(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	append_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	s[i] = c;
}

static void	rev_str(char *s)
{
	int	i;
	int	len_s;
	int	temp;

	i = 0;
	len_s = ft_strlen(s) - 1;
	while (i <= len_s / 2)
	{
		temp = s[i];
		s[i] = s[len_s - i];
		s[len_s - i] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		is_neg;
	long	nb;

	nb = (long)n;
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		nb = -nb;
	}
	res = ft_calloc(needed_chars(nb) + is_neg + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (nb == 0)
		append_str(res, '0');
	while (nb > 0)
	{
		append_str(res, nb % 10 + '0');
		nb = nb / 10;
	}
	if (is_neg)
		append_str(res, '-');
	rev_str(res);
	return (res);
}
