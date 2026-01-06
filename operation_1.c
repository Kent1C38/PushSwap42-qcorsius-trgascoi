/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:17:29 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 14:42:34 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:10:09 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/06 11:11:49 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stddef.h"

void	swap(t_stack **stack)
{
	t_stack	*next_stack;

	next_stack = (*stack)->next;
	(*stack)->next = next_stack->next;
	(*stack)->previous = next_stack;
	next_stack->previous = NULL;
	next_stack->next = (*stack);
	(*stack) = next_stack;
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

int	push(t_stack **from, t_stack **to)
{
	int	temp_val;

	temp_val = pop_stack(from);
	if (!push_stack(temp_val, to))
		return (0);
	return (1);
}

/*
#include "ft_printf.h"
int main(void)
{
    t_stack *stack = new_stack(1);
    push_stack(2, &stack);
    push_stack(3, &stack);
    swap(&stack);
    while (stack)
    {
        ft_printf("%d\n", stack->value);
        stack = stack->next;
    }
}
*/