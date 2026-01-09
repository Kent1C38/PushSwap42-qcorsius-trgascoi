/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADAPTIVE_SORT_H
# define ADAPTIVE_SORT_H

# include "push_swap.h"
# include "sort_utils.h"

double		compute_disorder(t_identified_stack *a);
t_sort_mode	adaptive_sort(t_identified_stack *a, t_identified_stack *b);

#endif
