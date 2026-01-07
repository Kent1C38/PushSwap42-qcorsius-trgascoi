/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:32:22 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 13:07:03 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:26:48 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/07 11:04:04 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/includes/ft_printf.h"

int	rotate(t_identified_stack *id_stack)
{
	int		value_to_move;
	t_stack	*tmp;

	if (!id_stack->content || !id_stack->content->next)
		return (0);
	value_to_move = pop_stack(&(id_stack->content));
	tmp = id_stack->content;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_stack(value_to_move);
	if (tmp->next == NULL)
		return (0);
	tmp->next->previous = tmp;
	if (id_stack->id != 0)
		ft_printf("r%c\n", id_stack->id);
	return (1);
}

int	rev_rotate(t_identified_stack *id_stack)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		value;

	stack = id_stack->content;
	if (!stack || !stack->next)
		return (0);
	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	value = tmp->value;
	if (tmp->previous)
		tmp->previous->next = NULL;
	free(tmp);
	if (id_stack->id != 0)
		ft_printf("rr%c\n", id_stack->id);
	return (push_stack(value, &(id_stack->content)));
}

void	rotate_both(t_identified_stack *a, t_identified_stack *b)
{
	char	id_a;
	char	id_b;

	id_a = a->id;
	id_b = b->id;
	a->id = 0;
	b->id = 0;
	rotate(a);
	rotate(b);
	a->id = id_a;
	b->id = id_b;
	ft_printf("rr\n");
}

void	rev_rotate_both(t_identified_stack *a, t_identified_stack *b)
{
	char	id_a;
	char	id_b;

	id_a = a->id;
	id_b = b->id;
	a->id = 0;
	b->id = 0;
	rev_rotate(a);
	rev_rotate(b);
	a->id = id_a;
	b->id = id_b;
	ft_printf("rrr\n");
}

/*
void	display_stack(t_identified_stack *id_stack)
{
	t_stack	*tmp;

	tmp = id_stack->content;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
int	main(void)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;

	stack_a.id = 'a';
	stack_a.content = new_stack(1);
	push_stack(2, &(stack_a.content));
	push_stack(3, &(stack_a.content));
	push_stack(4, &(stack_a.content));
	
	stack_b.id = 'b';
	stack_b.content = new_stack(10);
	push_stack(11, &(stack_b.content));
	push_stack(12, &(stack_b.content));
	push_stack(13, &(stack_b.content));
	
	push(&stack_b, &stack_a);
	
	display_stack(&stack_a);
	ft_printf("\n");
	display_stack(&stack_b);
}
*/