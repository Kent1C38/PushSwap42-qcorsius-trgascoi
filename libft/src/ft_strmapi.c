/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:41:12 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	s[i] = c;
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len_s;
	char	*res;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	res = ft_calloc(len_s + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		append_str(res, (*f)(i, s[i]));
		i++;
	}
	return (res);
}
