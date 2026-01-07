/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:02:56 by qcorsius          #+#    #+#             */
/*   Updated: 2026/01/07 17:51:10 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>

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
			if(!push_stack(ft_atoi(entries[index - 1]), &id_stack->content))
				return 0;
		index--;
	}
	return (1);
}

// int	option_handling(char *option, char *entry)
// {
// 	;
// }

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

int	main(int argc, char **argv)
{
	t_identified_stack	stack_a;
	t_identified_stack	stack_b;
	
	stack_a.id = 'a';
	stack_a.content = NULL;
	stack_b.id = 'b';
	stack_b.content = NULL;

	if (argc <= 1)
		return (0);
	else if (argc >= 2)
	{
		if (argv[1][0] != '-' && argv[1][1] != '-')
		{
			if (ft_string_check(argv[1], &ft_isdigit))
				generate_stack_from_entry(&argv[1], &stack_a);
			else
				generate_stack_from_entry(ft_split(argv[1], ' '), &stack_a);
		}
		else
			return (1);
	}	
	
	//push(&stack_a, &stack_b);
	ft_printf("stack a:\n");
	display_stack(&stack_a);
	ft_printf("\n\n");
	ft_printf("stack b:\n");
	display_stack(&stack_b);
	// if (argc <= 1)
	// 	return (0);
	// if (argc > 2)
	// {
	// 	if (argv[2][0] == '-')
	// 		return (option_handling(argv[2], argv[3]));
	// 	else
			
	// }
}
