/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:41:44 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/09 17:57:53 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "push_swap.h"

void	bench_init(t_op_counter *counter);
void	bench_count(t_op_counter *counter, char op, char stack_id);
void	bench_print(t_op_counter *counter, double disorder,
			t_sort_mode original_mode, t_sort_mode effective_mode);

#endif
