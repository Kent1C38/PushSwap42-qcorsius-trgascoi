/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:48:21 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 14:42:58 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	rotate(t_stack **stack)
{
	int		value_to_move;
	t_stack	*tmp;

	tmp = (*stack)->next;
	value_to_move = pop_stack(stack);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_stack(value_to_move);
	if (tmp->next == NULL)
		return (0);
	tmp->next->previous = tmp;
	return (1);
}

int	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (push_stack(pop_stack(&tmp), stack));
}

#include "ft_printf.h"
int	main(void)
{
	t_stack	*stack;

	stack = new_stack(1);
	push_stack(2, &stack);
	push_stack(3, &stack);
	push_stack(4, &stack);
	rev_rotate(&stack);
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}
