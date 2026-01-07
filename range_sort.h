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

#endif
