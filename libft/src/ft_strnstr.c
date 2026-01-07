/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:40:42 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	len_l;

	len_l = ft_strlen(little);
	if (n < (size_t)len_l || ft_strlen(big) < len_l)
		return (NULL);
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i <= n - len_l)
	{
		if (ft_strncmp(&big[i], little, len_l) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
