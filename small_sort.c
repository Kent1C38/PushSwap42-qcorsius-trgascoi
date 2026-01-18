/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/18 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort_utils.h"

int	selection_sort(t_identified_stack *a, t_identified_stack *b);

void	sort_two(t_identified_stack *a)
{
	if (a->content->value > a->content->next->value)
		swap(a);
}

void	sort_three(t_identified_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->content->value;
	second = a->content->next->value;
	third = a->content->next->next->value;
	if (first > second && second < third && first < third)
		swap(a);
	else if (first > second && second > third)
	{
		swap(a);
		rev_rotate(a);
	}
	else if (first > second && second < third && first > third)
		rotate(a);
	else if (first < second && second > third && first < third)
	{
		swap(a);
		rotate(a);
	}
	else if (first < second && second > third && first > third)
		rev_rotate(a);
}

int	small_sort(t_identified_stack *a, t_identified_stack *b)
{
	int	size;

	size = get_stack_size(a);
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		sort_two(a);
		return (1);
	}
	if (size == 3)
	{
		sort_three(a);
		return (1);
	}
	return (selection_sort(a, b));
}
