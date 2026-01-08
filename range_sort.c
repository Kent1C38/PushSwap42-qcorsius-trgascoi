/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 14:13:04 by trgascoi         ###   ########.fr       */
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
	while (b->content != NULL)
	{
		move_max_to_top_b(b);
		push(b, a);
	}
	free(sorted_arr);
}
