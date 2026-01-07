/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:50:06 by qcorsius          #+#    #+#             */
/*   Updated: 2025/11/21 15:44:30 by qcorsius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*clear(t_list **lst, void (*del)(void*), void *content)
{
	ft_lstclear(lst, (*del));
	if (content)
		free(content);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*ret;
	void	*tcontent;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	tmp = lst;
	ret = NULL;
	while (tmp)
	{
		tcontent = (*f)(tmp->content);
		if (tcontent == NULL)
			return (clear(&ret, (*del), NULL));
		new = ft_lstnew(tcontent);
		if (new == NULL)
			return (clear(&ret, (*del), tcontent));
		if (ret == NULL)
			ret = new;
		else
			ft_lstadd_back(&ret, new);
		tmp = tmp->next;
	}
	return (ret);
}
