/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:10:38 by parinder          #+#    #+#             */
/*   Updated: 2022/10/07 18:28:56 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*new;
	t_list	*anchor;

	if (!lst || !f || !del)
		return (0);
	element = lst;
	new = ft_lstnew(f(element->content));
	anchor = new;
	while (element->next)
	{
		if (!new)
		{
			ft_lstclear(&anchor, del);
			return (0);
		}
		element = element->next;
		ft_lstadd_back(&anchor, ft_lstnew(f(element->content)));
		new = new->next;
	}
	return (anchor);
}
