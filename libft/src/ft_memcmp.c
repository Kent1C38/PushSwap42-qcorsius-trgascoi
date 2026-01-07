/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:44:06 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (i < n)
	{
		if (p1[i] > p2[i])
			return (1);
		else if (p1[i] < p2[i])
			return (-1);
		i++;
	}
	return (0);
}
