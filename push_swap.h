/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:26:48 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 16:55:17 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:56:48 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/06 16:19:01 by qcorsius         ###   ########lyon.fr   */
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

typedef struct s_identified_stack
{
	char	id;
	t_stack	*content;
}	t_identified_stack;

t_stack	*new_stack(int value);
int		push_stack(int value, t_stack **stack);
int		pop_stack(t_stack **stack);

void	swap(t_identified_stack *id_stack);
int		push(t_identified_stack *from, t_identified_stack *to);
void	swap_both(t_identified_stack *a, t_identified_stack *b);
int		rotate(t_identified_stack *id_stack);
int		rev_rotate(t_identified_stack *id_stack);
void	rotate_both(t_identified_stack *a, t_identified_stack *b);
void	rev_rotate_both(t_identified_stack *a, t_identified_stack *b);

#endif