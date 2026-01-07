/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:34:29 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 14:35:01 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "push_swap.h"

int		min_value(t_identified_stack *id_stack);
int		get_stack_size(t_identified_stack *id_stack);
int		find_n_position(t_identified_stack *id_stack, int n);
void	move_n_to_top(t_identified_stack *stack_a, int n);

#endif
