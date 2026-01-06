/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:17:29 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 15:07:54 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stddef.h"
#include "ft_printf.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*next_stack;

	next_stack = (*stack)->next;
	(*stack)->next = next_stack->next;
	(*stack)->previous = next_stack;
	next_stack->previous = NULL;
	next_stack->next = (*stack);
	(*stack) = next_stack;
    if (c != 0)
        ft_printf("s%c\n", c);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a, 0);
	swap(b, 0);
    ft_printf("ss\n");
}

int	push(t_stack **from, t_stack **to, char c)
{
	int	temp_val;

	temp_val = pop_stack(from);
	if (!push_stack(temp_val, to))
		return (0);
    ft_printf("p%c\n", c);
	return (1);
}

/*

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