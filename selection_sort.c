/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:37:28 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 13:16:55 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	min_value(t_identified_stack *id_stack)
{
	t_stack	*stack;
	int		min_found;

	stack = id_stack->content;
	if (stack == NULL)
		return (0);
	min_found = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min_found)
			min_found = stack->value;
		stack = stack->next;
	}
	return (min_found);
}

int	selection_sort(t_identified_stack *stack_a, t_identified_stack *stack_b)
{
	t_stack	*stack;
	int		min;

	if (stack_a->content == NULL)
		return (0);
	while (stack_a->content != NULL)
	{
		stack = stack_a->content;
		min = min_value(stack_a);
		while (stack->value != min)
		{
			if (!rotate(stack_a))
				return (0);
			stack = stack_a->content;
		}
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

#include "ft_printf.h"
void	display_stack(t_identified_stack *id_stack)
{
	t_stack	*tmp;

	tmp = id_stack->content;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
int	main(void)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;

	stack_a.id = 'a';
	stack_a.content = new_stack(5);
	push_stack(7, &(stack_a.content));
	push_stack(3, &(stack_a.content));
	push_stack(6, &(stack_a.content));

	stack_b.id = 'b';
	stack_b.content = NULL;

	selection_sort(&stack_a, &stack_b);
	display_stack(&stack_a);
}
