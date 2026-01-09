/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:28:33 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 14:10:22 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"
#include "range_sort.h"
#include "radix_sort.h"
#include "adaptive_sort.h"
#include <unistd.h>
#include <stdlib.h>

int		selection_sort(t_identified_stack *stack_a,
			t_identified_stack *stack_b);
int		generate_stack_from_entry(char **entries, t_identified_stack *id_stack);
void	init_stacks(t_identified_stack *a, t_identified_stack *b);
void	display_stack(t_identified_stack *id_stack);

static void	execute_sort(t_identified_stack *a, t_identified_stack *b,
				t_sort_mode mode)
{
	if (mode == SORT_SIMPLE)
		selection_sort(a, b);
	else if (mode == SORT_MEDIUM)
		range_sort(a, b);
	else if (mode == SORT_COMPLEX)
		radix_sort(a, b);
	else
		adaptive_sort(a, b);
}

static int	parse_and_add_args(int argc, char **argv, int start,
				t_identified_stack *stack_a)
{
	char	**split;
	int		i;

	if (argc - start == 1 && ft_strchr(argv[start], ' '))
	{
		split = ft_split(argv[start], ' ');
		if (!split || !generate_stack_from_entry(split, stack_a))
		{
			i = 0;
			if (split)
			{
				while (split[i])
					free(split[i++]);
				free(split);
			}
			return (0);
		}
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
	else
		return (generate_stack_from_entry(&argv[start], stack_a));
	return (1);
}

int	main(int argc, char **argv)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;
	t_options			opt;
	int					start_index;

	init_stacks(&stack_a, &stack_b);
	if (argc <= 1)
		return (0);
	if (!parse_options(argc, argv, &opt, &start_index))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc > start_index)
	{
		if (!parse_and_add_args(argc, argv, start_index, &stack_a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	if (opt.benchmark_enabled)
		ft_printf("bench...");
	execute_sort(&stack_a, &stack_b, opt.sort_mode);
	return (0);
}
