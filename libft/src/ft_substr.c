/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:43:10 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t t1, size_t t2)
{
	if (t1 > t2)
		return (t2);
	return (t1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		sub_len;
	int		i;
	int		st;
	char	*sub;

	if (s == NULL)
		return (NULL);
	st = (int) min(start, ft_strlen(s));
	sub_len = (int) min(ft_strlen(s) - st, len);
	sub = ft_calloc(sub_len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[st + i] != '\0' && i < sub_len)
	{
		sub[i] = s[st + i];
		i++;
	}
	return (sub);
}
