/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:00:37 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/09 17:57:16 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>

void	init_stacks(t_identified_stack *a, t_identified_stack *b)
{
	a->id = 'a';
	a->content = NULL;
	a->counter = NULL;
	b->id = 'b';
	b->content = NULL;
	b->counter = NULL;
}

int	generate_stack_from_entry(char **entries, t_identified_stack *id_stack)
{
	int		index;
	int		value;

	index = 0;
	while (entries[index])
	{
		if (!entries[index][0])
			return (0);
		if (!is_valid_int(entries[index]))
			return (0);
		index++;
	}
	while (index > 0)
	{
		value = ft_atoi(entries[index - 1]);
		if (has_duplicate(id_stack->content, value))
			return (0);
		if (id_stack->content == NULL)
			id_stack->content = new_stack(value);
		else
			if (!push_stack(value, &id_stack->content))
				return (0);
		index--;
	}
	return (1);
}

void	display_stack(t_identified_stack *id_stack)
{
	t_stack	*tmp;

	if (id_stack->content == NULL)
		ft_printf("(empty)");
	tmp = id_stack->content;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
