/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 15:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGE_SORT_H
# define RANGE_SORT_H

# include "push_swap.h"
# include "sort_utils.h"

void	range_sort(t_identified_stack *a, t_identified_stack *b);
int		*create_sorted_array(t_identified_stack *a, int size);
int		get_rank(int value, int *sorted_arr, int size);
void	push_to_b_with_range(t_identified_stack *a, t_identified_stack *b,
			int *sorted, int size);
int		max_value_in_stack(t_identified_stack *stack);
int		find_position(t_identified_stack *stack, int value);
void	move_max_to_top_b(t_identified_stack *b);
void	push_back_to_a(t_identified_stack *a, t_identified_stack *b);

#endif
