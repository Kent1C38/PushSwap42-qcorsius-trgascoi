/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 14:13:21 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range_sort.h"
#include <stdlib.h>

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

void	push_to_b_with_range(t_identified_stack *a, t_identified_stack *b,
	int *sorted, int size)
{
	int	i;
	int	range;
	int	rank;

	i = 0;
	range = ft_sqrt(size);
	while (a->content != NULL)
	{
		rank = get_rank(a->content->value, sorted, size);
		if (rank <= i)
		{
			push(a, b);
			i++;
		}
		else if (rank <= i + range)
		{
			push(a, b);
			rotate(b);
			i++;
		}
		else
			rotate(a);
	}
}

int	max_value_in_stack(t_identified_stack *stack)
{
	t_stack	*tmp;
	int		max;

	tmp = stack->content;
	if (!tmp)
		return (0);
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	find_position(t_identified_stack *stack, int value)
{
	t_stack	*tmp;
	int		pos;

	tmp = stack->content;
	pos = 0;
	while (tmp)
	{
		if (tmp->value == value)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

void	move_max_to_top_b(t_identified_stack *b)
{
	int	max;
	int	pos;
	int	size;

	max = max_value_in_stack(b);
	pos = find_position(b, max);
	size = get_stack_size(b);
	if (pos <= size / 2)
	{
		while (b->content && b->content->value != max)
			rotate(b);
	}
	else
	{
		while (b->content && b->content->value != max)
			rev_rotate(b);
	}
}
