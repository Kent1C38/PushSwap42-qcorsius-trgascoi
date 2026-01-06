/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:27:19 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/06 10:00:17 by qcorsius         ###   ########lyon.fr   */
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

void	clear_stack_value(t_stack *stack)
{
	stack->next = NULL;
	stack->previous = NULL;
}

void	push_stack(int value, t_stack *stack)
{
	t_stack	*modified;

	modified = new_stack(value);
	modified->next = stack;
	stack->previous = modified;
	stack = modified;
}

int	pop_stack(t_stack *stack)
{
	
}

