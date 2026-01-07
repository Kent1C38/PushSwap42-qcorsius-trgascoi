/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 15:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range_sort.h"
#include <stdlib.h>

static void	insertion_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	*create_sorted_array(t_identified_stack *a, int size)
{
	int		*arr;
	t_stack	*tmp;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = a->content;
	i = 0;
	while (tmp && i < size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	insertion_sort_array(arr, size);
	return (arr);
}

int	get_rank(int value, int *sorted_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	calculate_range(int size)
{
	if (size <= 100)
		return (15);
	return (35);
}

static void	push_to_b_with_range(t_identified_stack *a, t_identified_stack *b,
	int *sorted, int size)
{
	int	i;
	int	range;
	int	rank;

	i = 0;
	range = calculate_range(size);
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

static int	max_value_in_stack(t_identified_stack *stack)
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

static int	find_position(t_identified_stack *stack, int value)
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

static void	move_max_to_top_b(t_identified_stack *b)
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

static void	push_back_to_a(t_identified_stack *a, t_identified_stack *b)
{
	while (b->content != NULL)
	{
		move_max_to_top_b(b);
		push(b, a);
	}
}

void	range_sort(t_identified_stack *a, t_identified_stack *b)
{
	int	*sorted_arr;
	int	size;

	size = get_stack_size(a);
	if (size <= 1)
		return ;
	sorted_arr = create_sorted_array(a, size);
	if (!sorted_arr)
		return ;
	push_to_b_with_range(a, b, sorted_arr, size);
	push_back_to_a(a, b);
	free(sorted_arr);
}
