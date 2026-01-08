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
#include <string.h>

int		selection_sort(t_identified_stack *stack_a,
			t_identified_stack *stack_b);
void	init_stacks(t_identified_stack *a, t_identified_stack *b);
void	parse_and_generate(char **argv, int idx, t_identified_stack *a);

static void	run_sort(char *mode, t_identified_stack *a, t_identified_stack *b)
{
	if (!strcmp(mode, "--simple"))
		selection_sort(a, b);
	else if (!strcmp(mode, "--medium"))
		range_sort(a, b);
	else if (!strcmp(mode, "--complex"))
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;
	int					start_index;

	init_stacks(&stack_a, &stack_b);
	if (argc <= 1)
		return (0);
	start_index = 1;
	if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == '-')
		start_index = 2;
	if (argc > start_index)
		parse_and_generate(argv, start_index, &stack_a);
	if (start_index == 2)
		run_sort(argv[1], &stack_a, &stack_b);
	return (0);
}
