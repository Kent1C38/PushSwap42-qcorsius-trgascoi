/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:56:48 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 15:13:52 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:16:27 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/06 11:09:55 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_stack(int value);
int		push_stack(int value, t_stack **stack);
int		pop_stack(t_stack **stack);
void	swap(t_stack **stack, char c);
void	swap_both(t_stack **a, t_stack **b);
int	push(t_stack **from, t_stack **to, char c);

#endif