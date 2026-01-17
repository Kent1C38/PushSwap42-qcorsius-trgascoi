/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:32:22 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/17 13:45:46 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "benchmark.h"
#include "libft/includes/ft_printf.h"

int	rotate(t_identified_stack *id_stack)
{
	int		value_to_move;
	t_stack	*tmp;

	if (!id_stack->content || !id_stack->content->next)
		return (0);
	value_to_move = pop_stack(&(id_stack->content));
	tmp = id_stack->content;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_stack(value_to_move);
	if (tmp->next == NULL)
		return (0);
	tmp->next->previous = tmp;
	if (id_stack->id != 0)
	{
		bench_count(id_stack->counter, 'r', id_stack->id);
		ft_printf("r%c\n", id_stack->id);
	}
	return (1);
}

int	rev_rotate(t_identified_stack *id_stack)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		value;

	stack = id_stack->content;
	if (!stack || !stack->next)
		return (0);
	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	value = tmp->value;
	if (tmp->previous)
		tmp->previous->next = NULL;
	free(tmp);
	if (id_stack->id != 0)
	{
		bench_count(id_stack->counter, 'v', id_stack->id);
		ft_printf("rr%c\n", id_stack->id);
	}
	return (push_stack(value, &(id_stack->content)));
}

void	rotate_both(t_identified_stack *a, t_identified_stack *b)
{
	char	id_a;
	char	id_b;

	id_a = a->id;
	id_b = b->id;
	a->id = 0;
	b->id = 0;
	rotate(a);
	rotate(b);
	a->id = id_a;
	b->id = id_b;
	bench_count(a->counter, 'R', 0);
	ft_printf("rr\n");
}

void	rev_rotate_both(t_identified_stack *a, t_identified_stack *b)
{
	char	id_a;
	char	id_b;

	id_a = a->id;
	id_b = b->id;
	a->id = 0;
	b->id = 0;
	rev_rotate(a);
	rev_rotate(b);
	a->id = id_a;
	b->id = id_b;
	bench_count(a->counter, 'V', 0);
	ft_printf("rrr\n");
}
