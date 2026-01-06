/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:48:21 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 15:16:24 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

int	rotate(t_stack **stack, char c)
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
	ft_printf("r%c\n", c);
	return (1);
}

int	rev_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	ft_printf("rr%c\n", c);
	return (push_stack(pop_stack(&tmp), stack));
}

int	main(void)
{
	t_stack	*stack;
	t_stack	*stackb;

	stack = new_stack(1);
	push_stack(2, &stack);
	push_stack(3, &stack);
	push_stack(4, &stack);
	
	stackb = new_stack(10);
	push_stack(11, &stackb);
	push_stack(12, &stackb);
	push_stack(13, &stackb);
	
	push(&stackb, &stack, 'b');
	
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}

	ft_printf("\n\n");
	
	while (stackb)
	{
		ft_printf("%d\n", stackb->value);
		stackb = stackb->next;
	}
}
