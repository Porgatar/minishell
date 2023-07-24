/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:30:46 by parinder          #+#    #+#             */
/*   Updated: 2022/10/04 22:45:27 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	if (!dst && !size)
		return (0);
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size >= size)
		return (size + src_size);
	i = 0;
	while (src[i] && dst_size + i < size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = 0;
	return (dst_size + src_size);
}
