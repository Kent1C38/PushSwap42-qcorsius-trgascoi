/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:02:28 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/07 17:09:46 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_string_check(char *string, int (*f)(int))
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!f(string[i]))
			return (0);
		i++;
	}
	return (1);
}
