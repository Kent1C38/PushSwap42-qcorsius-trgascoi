/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:42:28 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_for_malloc(char const *s, char c)
{
	int	i;
	int	count;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count + 1);
}

static void	append_arr(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	arr[i] = str;
}

static void	*free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		start;
	char	**array;
	char	*temp;

	array = ft_calloc(count_for_malloc(s, c), sizeof(char *));
	if (array == NULL || s == NULL)
		return (NULL);
	i = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (start == -1 && s[i] != c && s[i] != '\0')
			start = i;
		else if (start != -1 && (s[i] == c || s[i] == '\0'))
		{
			temp = ft_substr(s, start, i - start);
			if (!temp)
				return (free_all(array));
			append_arr(array, temp);
			start = -1;
		}
		i++;
	}
	return (array);
}
