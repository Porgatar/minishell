/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:16:45 by parinder          #+#    #+#             */
/*   Updated: 2022/10/09 17:06:13 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 1 && nmemb * size == 1)
		return (0);
	ptr = malloc(size * nmemb);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
