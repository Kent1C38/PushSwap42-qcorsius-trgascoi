/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_SORT_H
# define RADIX_SORT_H

# include "push_swap.h"
# include "sort_utils.h"

typedef struct s_sort_ctx
{
	int	*sorted;
	int	size;
}				t_sort_ctx;

void	radix_sort(t_identified_stack *a, t_identified_stack *b);

#endif
