/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:26:48 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 09:48:44 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stddef.h"
#include "ft_printf.h"

void	swap(t_identified_stack *id_stack)
{
	t_stack	**stack;
	t_stack	*next_stack;

	stack = &(id_stack->content);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	next_stack = (*stack)->next;
	(*stack)->next = next_stack->next;
	(*stack)->previous = next_stack;
	if (next_stack->next != NULL)
		next_stack->next->previous = (*stack);
	next_stack->previous = NULL;
	next_stack->next = (*stack);
	(*stack) = next_stack;
	if (id_stack->id != 0)
		ft_printf("s%c\n", id_stack->id);
}

void	swap_both(t_identified_stack *a, t_identified_stack *b)
{
	char	id_a;
	char	id_b;

	id_a = a->id;
	id_b = b->id;
	a->id = 0;
	b->id = 0;
	swap(a);
	swap(b);
	a->id = id_a;
	b->id = id_b;
	ft_printf("ss\n");
}

int	push(t_identified_stack *from, t_identified_stack *to)
{
	int	temp_val;

	if (from->content == NULL)
		return (0);
	temp_val = pop_stack(&(from->content));
	if (!push_stack(temp_val, &(to->content)))
		return (0);
	ft_printf("p%c\n", to->id);
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