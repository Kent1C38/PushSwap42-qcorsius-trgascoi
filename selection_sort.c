/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:37:28 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 15:27:45 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "sort_utils.h"

int	selection_sort(t_identified_stack *stack_a, t_identified_stack *stack_b)
{
	int		min;

	if (stack_a->content == NULL)
		return (0);
	while (stack_a->content != NULL)
	{
		min = min_value(stack_a);
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

#include "libft/includes/ft_printf.h"
#include "range_sort.h"
#include <time.h>
int is_unique(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void fill_random_stack(t_identified_stack *stack_a, int count)
{
	int random_val;
	int i = 0;

	srand(time(NULL));
	stack_a->content = NULL;
	while (i < count)
	{
		random_val = rand() % 10000; // Adjust range as needed
		if (is_unique(stack_a->content, random_val))
		{
			if (stack_a->content == NULL)
				stack_a->content = new_stack(random_val);
			else
				push_stack(random_val, &(stack_a->content));
			i++;
		}
	}
}
void	display_stack(t_identified_stack *id_stack)
{
	t_stack	*tmp;

	tmp = id_stack->content;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
int	main(void)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;

	stack_a.id = 'a';
	fill_random_stack(&stack_a, 500);

	stack_b.id = 'b';
	stack_b.content = NULL;

	// display_stack(&stack_a);
	range_sort(&stack_a, &stack_b);
	// display_stack(&stack_a);
}
