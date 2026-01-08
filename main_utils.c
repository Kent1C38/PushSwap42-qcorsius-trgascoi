/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:00:00 by trgascoi          #+#    #+#             */
/*   Updated: 2026/01/08 00:00:00 by trgascoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"

int	generate_stack_from_entry(char **entries, t_identified_stack *id_stack)
{
	int		index;

	index = 0;
	while (entries[index])
		index++;
	while (index > 0)
	{
		if (id_stack->content == NULL)
			id_stack->content = new_stack(ft_atoi(entries[index - 1]));
		else
			if (!push_stack(ft_atoi(entries[index - 1]), &id_stack->content))
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

void	init_stacks(t_identified_stack *a, t_identified_stack *b)
{
	a->id = 'a';
	a->content = NULL;
	b->id = 'b';
	b->content = NULL;
}

int	is_numeric_arg(char *arg)
{
	if (arg[0] == '-' && ft_string_check(&arg[1], &ft_isdigit))
		return (1);
	return (ft_string_check(arg, &ft_isdigit));
}

void	parse_and_generate(char **argv, int idx, t_identified_stack *a)
{
	if (is_numeric_arg(argv[idx]))
		generate_stack_from_entry(&argv[idx], a);
	else
		generate_stack_from_entry(ft_split(argv[idx], ' '), a);
}
