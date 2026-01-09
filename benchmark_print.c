/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:49:46 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/09 17:56:52 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "libft/includes/ft_printf.h"

static const char	*get_strategy_name(t_sort_mode mode)
{
	if (mode == SORT_SIMPLE)
		return ("Simple O(n^2)");
	else if (mode == SORT_MEDIUM)
		return ("Medium O(n*sqrt(n))");
	else if (mode == SORT_COMPLEX)
		return ("Complex O(n*log(n))");
	return ("Adaptive");
}

static void	print_disorder(double disorder)
{
	int	d_int;
	int	d_dec;

	d_int = (int)(disorder * 100);
	d_dec = (int)(disorder * 10000) % 100;
	if (d_dec < 10)
		ft_printf("\n[bench] Disorder: %d.0%d%%\n", d_int, d_dec);
	else
		ft_printf("\n[bench] Disorder: %d.%d%%\n", d_int, d_dec);
}

void	bench_print(t_op_counter *c, double disorder, t_sort_mode mode)
{
	if (!c)
		return ;
	print_disorder(disorder);
	ft_printf("[bench] Strategy: %s\n", get_strategy_name(mode));
	ft_printf("[bench] Total operations: %d\n", c->total);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d\n", c->sa, c->sb, c->ss);
	ft_printf("pa: %d, pb: %d\n", c->pa, c->pb);
	ft_printf("ra: %d, rb: %d, rr: %d\n", c->ra, c->rb, c->rr);
	ft_printf("rra: %d, rrb: %d, rrr: %d\n", c->rra, c->rrb, c->rrr);
}
