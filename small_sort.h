/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/18 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALL_SORT_H
# define SMALL_SORT_H

# include "push_swap.h"

int		selection_sort(t_identified_stack *a, t_identified_stack *b);
void	sort_two(t_identified_stack *a);
void	sort_three(t_identified_stack *a);
int		small_sort(t_identified_stack *a, t_identified_stack *b);

#endif
