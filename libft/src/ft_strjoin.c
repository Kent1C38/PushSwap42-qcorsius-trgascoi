/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:41:57 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buff;
	int		buff_size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buff_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buff = ft_calloc(buff_size, sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, s1, buff_size);
	ft_strlcat(buff, s2, buff_size);
	return (buff);
}
