/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:30:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 14:35:54 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"
#include <stdlib.h>

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

int	get_stack_size(t_identified_stack *id_stack)
{
	t_stack	*stack;
	int		size;

	stack = id_stack->content;
	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_n_position(t_identified_stack *id_stack, int n)
{
	t_stack	*stack;
	int		position;

	stack = id_stack->content;
	position = 0;
	while (stack != NULL)
	{
		if (stack->value == n)
			return (position);
		position++;
		stack = stack->next;
	}
	return (0);
}

void	move_n_to_top(t_identified_stack *stack_a, int n)
{
	int		position;
	int		size;
	int		distance_from_top;
	int		distance_from_bottom;

	position = find_n_position(stack_a, n);
	size = get_stack_size(stack_a);
	distance_from_top = position;
	distance_from_bottom = size - position;
	if (distance_from_top <= distance_from_bottom)
	{
		while (stack_a->content->value != n)
			rotate(stack_a);
	}
	else
	{
		while (stack_a->content->value != n)
			rev_rotate(stack_a);
	}
}
