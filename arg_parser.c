/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:10:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/12 14:11:32 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"
#include <stdlib.h>

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	process_one_arg(char *arg, t_identified_stack *stack_a)
{
	char	**split;
	int		ret;

	if (ft_strchr(arg, ' '))
	{
		split = ft_split(arg, ' ');
		if (!split)
			return (0);
		ret = generate_stack_from_entry(split, stack_a);
		free_split(split);
		return (ret);
	}
	return (add_one_entry(arg, stack_a));
}
