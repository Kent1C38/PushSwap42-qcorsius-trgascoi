/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adaptive_sort.h"
#include "range_sort.h"
#include "radix_sort.h"
#include <stddef.h>

int	selection_sort(t_identified_stack *stack_a, t_identified_stack *stack_b);

static int	count_mistakes(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		mistakes;

	mistakes = 0;
	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes);
}

double	compute_disorder(t_identified_stack *a)
{
	int	size;
	int	total_pairs;
	int	mistakes;

	size = get_stack_size(a);
	if (size <= 1)
		return (0.0);
	total_pairs = (size * (size - 1)) / 2;
	mistakes = count_mistakes(a->content);
	return ((double)mistakes / (double)total_pairs);
}

void	adaptive_sort(t_identified_stack *a, t_identified_stack *b)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		selection_sort(a, b);
	else if (disorder < 0.5)
		range_sort(a, b);
	else
		radix_sort(a, b);
}
