/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:58:05 by parinder          #+#    #+#             */
/*   Updated: 2022/10/06 18:30:27 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*element;

	if (!list || !new)
		return ;
	if (!*list)
		*list = new;
	else
	{
		element = ft_lstlast(*list);
		element->next = new;
	}
}
