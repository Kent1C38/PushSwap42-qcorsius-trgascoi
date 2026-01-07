/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:37:28 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 15:36:35 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "sort_utils.h"

int	selection_sort(t_identified_stack *stack_a, t_identified_stack *stack_b)
{
	int		min;

	if (stack_a->content == NULL)
		return (0);
	while (stack_a->content != NULL)
	{
		min = min_value(stack_a);
		move_n_to_top(stack_a, min);
		if (!push(stack_a, stack_b))
			return (0);
	}
	while (stack_b->content != NULL)
	{
		if (!push(stack_b, stack_a))
			return (0);
	}
	return (1);
}

// #include "ft_printf.h"
// void	display_stack(t_identified_stack *id_stack)
// {
// 	t_stack	*tmp;

// 	tmp = id_stack->content;
// 	while (tmp)
// 	{
// 		ft_printf("%d\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// }
// int	main(void)
// {
// 	t_identified_stack	stack_a;
// 	t_identified_stack	stack_b;

// 	stack_a.id = 'a';
// 	stack_a.content = new_stack(1);
// 	push_stack(2, &(stack_a.content));
// 	push_stack(3, &(stack_a.content));
// 	push_stack(4, &(stack_a.content));

// 	stack_b.id = 'b';
// 	stack_b.content = NULL;

// 	// display_stack(&stack_a);
// 	selection_sort(&stack_a, &stack_b);
// 	// display_stack(&stack_a);
// }
