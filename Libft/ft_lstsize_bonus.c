/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:54:28 by parinder          #+#    #+#             */
/*   Updated: 2022/10/06 18:05:00 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*element;
	int		i;

	i = 0;
	element = lst;
	while (element)
	{
		element = element->next;
		i++;
	}
	return (i);
}
