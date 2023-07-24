/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:10:05 by parinder          #+#    #+#             */
/*   Updated: 2022/10/06 19:19:27 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;

	if (!lst || !del)
		return ;
	element = *lst;
	while (element)
	{
		del(element->content);
		element = element->next;
		free(*lst);
		*lst = element;
	}
	lst = 0;
}
