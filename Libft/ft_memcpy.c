/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:13:42 by parinder          #+#    #+#             */
/*   Updated: 2022/10/04 20:51:55 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s_tmp;
	unsigned char		*d_tmp;
	size_t				i;

	if (dest == 0 && src == 0)
		return (0);
	s_tmp = src;
	d_tmp = dest;
	i = 0;
	while (i < n)
	{
		d_tmp[i] = s_tmp[i];
		i++;
	}
	return (dest);
}
