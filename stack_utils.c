/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:27:19 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/07 16:40:40 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

int	push_stack(int value, t_stack **stack)
{
	t_stack	*modified;

	modified = new_stack(value);
	if (!modified)
		return (0);
	if (*stack != NULL && stack != NULL)
	{
		modified->next = *stack;
		(*stack)->previous = modified;
		*stack = modified;
	}
	else if (stack != NULL)
		*stack = modified;
	else
		return (0);
	return (1);
}

int	pop_stack(t_stack **stack)
{
	int		value;
	t_stack	*new_stack;

	if (*stack == NULL)
		return (0);
	value = (*stack)->value;
	new_stack = (*stack)->next;
	free(*stack);
	if (new_stack != NULL)
	{
		new_stack->previous = NULL;
		*stack = new_stack;
	}
	else
		*stack = NULL;
	return (value);
}
