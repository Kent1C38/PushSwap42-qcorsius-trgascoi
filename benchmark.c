/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:41:44 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/09 17:56:38 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

void	bench_init(t_op_counter *counter)
{
	counter->sa = 0;
	counter->sb = 0;
	counter->ss = 0;
	counter->pa = 0;
	counter->pb = 0;
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
	counter->total = 0;
}

static void	bench_count_swap_push(t_op_counter *c, char op, char stack_id)
{
	if (op == 's' && stack_id == 'a')
		c->sa++;
	else if (op == 's' && stack_id == 'b')
		c->sb++;
	else if (op == 'S')
		c->ss++;
	else if (op == 'p' && stack_id == 'a')
		c->pa++;
	else if (op == 'p' && stack_id == 'b')
		c->pb++;
}

static void	bench_count_rotate(t_op_counter *c, char op, char stack_id)
{
	if (op == 'r' && stack_id == 'a')
		c->ra++;
	else if (op == 'r' && stack_id == 'b')
		c->rb++;
	else if (op == 'R')
		c->rr++;
	else if (op == 'v' && stack_id == 'a')
		c->rra++;
	else if (op == 'v' && stack_id == 'b')
		c->rrb++;
	else if (op == 'V')
		c->rrr++;
}

void	bench_count(t_op_counter *counter, char op, char stack_id)
{
	if (!counter)
		return ;
	counter->total++;
	bench_count_swap_push(counter, op, stack_id);
	bench_count_rotate(counter, op, stack_id);
}
