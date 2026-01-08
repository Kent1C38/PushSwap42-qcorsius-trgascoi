/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 14:56:53 by trgascoi         ###   ########.fr       */
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

static void	sort_by_bit(t_identified_stack *a, t_identified_stack *b,
	t_sort_ctx *ctx, int bit)
{
	int	i;
	int	rank;

	i = 0;
	while (i < ctx->size)
	{
		rank = get_rank(a->content->value, ctx->sorted, ctx->size);
		if (!((rank >> bit) & 1))
			push(a, b);
		else
			rotate(a);
		i++;
	}
}

static void	push_all_back(t_identified_stack *a, t_identified_stack *b)
{
	while (b->content != NULL)
		push(b, a);
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
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(a, b, &ctx, bit);
		push_all_back(a, b);
		bit++;
	}
	free(ctx.sorted);
}
