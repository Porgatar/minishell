/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:24:19 by parinder          #+#    #+#             */
/*   Updated: 2022/10/07 18:36:55 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s_tmp;
	unsigned char		*d_tmp;
	size_t				i;

	if (dest == 0 && src == 0)
		return (0);
	s_tmp = src;
	d_tmp = dest;
	i = n;
	while (i > 0)
	{
		i--;
		d_tmp[i] = s_tmp[i];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		ft_memrcpy(dest, src, n);
	return (dest);
}
