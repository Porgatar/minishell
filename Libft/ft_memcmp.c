/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:49:38 by parinder          #+#    #+#             */
/*   Updated: 2022/09/28 18:49:51 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	if (n == 0)
		return (0);
	s1_ptr = s1;
	s2_ptr = s2;
	i = 0;
	while (i < n - 1 && s1_ptr[i] == s2_ptr[i])
			i++;
	return (s1_ptr[i] - s2_ptr[i]);
}
