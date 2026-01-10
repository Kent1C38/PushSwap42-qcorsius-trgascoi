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
#include "benchmark.h"
#include "libft/includes/libft.h"
#include "adaptive_sort.h"
#include <unistd.h>
#include <stdlib.h>

int			selection_sort(t_identified_stack *stack_a,
				t_identified_stack *stack_b);
int			generate_stack_from_entry(char **entries,
				t_identified_stack *id_stack);
void		init_stacks(t_identified_stack *a, t_identified_stack *b);
void		display_stack(t_identified_stack *id_stack);
t_sort_mode	execute_sort(t_identified_stack *a, t_identified_stack *b,
				t_sort_mode mode);

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

static void	setup_bench(t_options *opt, t_identified_stack *a,
				t_identified_stack *b, t_op_counter *counter)
{
	if (opt->benchmark_enabled)
	{
		bench_init(counter);
		a->counter = counter;
		b->counter = counter;
		a->silent = 1;
		b->silent = 1;
	}
}

static int	process_args(int argc, char **argv, t_identified_stack *a,
				t_options *opt)
{
	int	start_index;

	if (!parse_options(argc, argv, opt, &start_index))
		return (0);
	if (argc > start_index)
		if (!parse_and_add_args(argc, argv, start_index, a))
			return (0);
	return (1);
}

static void	run_sort(t_identified_stack *a, t_identified_stack *b,
				t_options *opt, t_op_counter *counter)
{
	setup_bench(opt, a, b, counter);
	if (opt->benchmark_enabled)
		opt->disorder = compute_disorder(a);
	opt->effective_mode = execute_sort(a, b, opt->sort_mode);
	if (opt->benchmark_enabled)
		bench_print(counter, opt->disorder, opt->sort_mode,
			opt->effective_mode);
}

int	main(int argc, char **argv)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;
	t_options			opt;
	t_op_counter		counter;

	init_stacks(&stack_a, &stack_b);
	if (argc <= 1)
		return (0);
	if (!process_args(argc, argv, &stack_a, &opt))
	{
		free_stack(&stack_a.content);
		free_stack(&stack_b.content);
		return (write(2, "Error\n", 6), 1);
	}
	run_sort(&stack_a, &stack_b, &opt, &counter);
	free_stack(&stack_a.content);
	free_stack(&stack_b.content);
	return (0);
}
