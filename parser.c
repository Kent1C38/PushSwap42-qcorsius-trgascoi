/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:58:17 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/09 11:22:26 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

int	options_check(int *index, int argc, char **argv, t_options *opt)
{
	while (*index < argc && argv[*index][0] == '-' && argv[*index][1] == '-')
	{
		if (!(ft_strcmp(argv[*index], "--bench") == 0))
		{
			if (opt->sort_mode != SORT_NONE)
				return (0);
			if (!ft_strcmp(argv[*index], "--simple"))
				opt->sort_mode = SORT_SIMPLE;
			else if (!ft_strcmp(argv[*index], "--medium"))
				opt->sort_mode = SORT_MEDIUM;
			else if (!ft_strcmp(argv[*index], "--complex"))
				opt->sort_mode = SORT_COMPLEX;
			else if (!ft_strcmp(argv[*index], "--adaptive"))
				opt->sort_mode = SORT_ADAPTATIVE;
			else
				return (0);
		}
		else
			opt->benchmark_enabled = 1;
		*index = *index + 1;
	}
	return (1);
}

int	parse_options(int argc, char **argv, t_options *opt, int *start_index)
{
	int	i;

	opt->sort_mode = SORT_NONE;
	opt->benchmark_enabled = 0;
	i = 1;
	options_check(&i, argc, argv, opt);
	*start_index = i;
	return (1);
}
