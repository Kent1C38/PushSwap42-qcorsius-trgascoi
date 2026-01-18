/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/17 12:42:13 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "radix_sort.h"
#include "range_sort.h"
#include <stdlib.h>

static int	get_max_bits(int size)
{
	int	bits;
	int	max_num;

	max_num = size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_push_from_a(t_identified_stack *a, t_identified_stack *b,
		t_sort_ctx *ctx, int bit)
{
	int	i;
	int	size_a;
	int	rank;

	i = 0;
	size_a = get_stack_size(a);
	while (i < size_a)
	{
		rank = get_rank(a->content->value, ctx->sorted, ctx->size);
		if (!((rank >> bit) & 1))
			push(a, b);
		else
			rotate(a);
		i++;
	}
}

static void	radix_push_from_b(t_identified_stack *a, t_identified_stack *b,
	t_sort_ctx *ctx, int bit)
{
	int	i;
	int	size_b;
	int	rank;
	int	max_bits;

	i = 0;
	size_b = get_stack_size(b);
	max_bits = get_max_bits(ctx->size);
	while (i < size_b)
	{
		rank = get_rank(b->content->value, ctx->sorted, ctx->size);
		if ((rank >> (bit + 1)) & 1 || bit == max_bits - 1)
			push(b, a);
		else
			rotate(b);
		i++;
	}
}

void	radix_sort(t_identified_stack *a, t_identified_stack *b)
{
	t_sort_ctx	ctx;
	int			max_bits;
	int			bit;

	ctx.size = get_stack_size(a);
	if (ctx.size <= 1)
		return ;
	ctx.sorted = create_sorted_array(a, ctx.size);
	if (!ctx.sorted)
		return ;
	max_bits = get_max_bits(ctx.size);
	bit = -1;
	while (++bit < max_bits)
	{
		radix_push_from_a(a, b, &ctx, bit);
		radix_push_from_b(a, b, &ctx, bit);
	}
	free(ctx.sorted);
}
