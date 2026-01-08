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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:02:56 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/07 17:51:10 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"
#include "range_sort.h"
#include <string.h>

int	selection_sort(t_identified_stack *stack_a, t_identified_stack *stack_b);

int	generate_stack_from_entry(char **entries, t_identified_stack *id_stack)
{
	int		index;

	index = 0;
	while (entries[index])
		index++;
	while (index > 0)
	{
		if (id_stack->content == NULL)
			id_stack->content = new_stack(ft_atoi(entries[index - 1]));
		else
			if (!push_stack(ft_atoi(entries[index - 1]), &id_stack->content))
				return (0);
		index--;
	}
	return (1);
}

void	display_stack(t_identified_stack *id_stack)
{
	t_stack	*tmp;

	if (id_stack->content == NULL)
		ft_printf("(empty)");
	tmp = id_stack->content;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;
	t_options			opt;
	int					start_index;

	stack_a.id = 'a';
	stack_a.content = NULL;
	stack_b.id = 'b';
	stack_b.content = NULL;
	if (argc < 1)
		return (0);
	if (!parse_options(argc, argv, &opt, &start_index)) {
		ft_printf("Error: invalid options\n");
		return (1);
	}
	if (argc > start_index)
		generate_stack_from_entry(&argv[start_index], &stack_a);
	if (opt.benchmark_enabled)
		ft_printf("bench...");
	if (opt.sort_mode == SORT_SIMPLE)
		selection_sort(&stack_a, &stack_b);
	else if (opt.sort_mode == SORT_MEDIUM)
		range_sort(&stack_a, &stack_b);
	// else if (opt.sort_mode == SORT_COMPLEX)
	// 	;
	// else if (opt.sort_mode == SORT_ADAPTATIVE)
	// 	;

	display_stack(&stack_a);
	return (0);
}
