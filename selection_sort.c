/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:28:33 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 14:08:58 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "sort_utils.h"
#include "small_sort.h"

int	selection_sort(t_identified_stack *stack_a, t_identified_stack *stack_b)
{
	int		min;
	int		size;

	if (stack_a->content == NULL)
		return (0);
	size = get_stack_size(stack_a);
	if (size <= 3)
		return (small_sort(stack_a, stack_b));
	while (stack_a->content != NULL)
	{
		min = min_value(stack_a);
		if (stack_a->content->next
			&& stack_a->content->next->value == min)
			swap(stack_a);
		else
			move_n_to_top(stack_a, min);
		if (!push(stack_a, stack_b))
			return (0);
	}
	while (stack_b->content != NULL)
	{
		if (!push(stack_b, stack_a))
			return (0);
	}
	return (1);
}
