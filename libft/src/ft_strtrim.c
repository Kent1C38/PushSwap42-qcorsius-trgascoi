/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:43:16 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = (int) ft_strlen(s1)-1;
	start = 0;
	while (contains(s1[start], set))
		start++;
	while (contains(s1[end], set))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
