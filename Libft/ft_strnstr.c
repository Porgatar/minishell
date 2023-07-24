/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:11:04 by parinder          #+#    #+#             */
/*   Updated: 2022/10/04 20:18:29 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;

	if (big == 0 && len == 0)
		return (0);
	if (!(*little))
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			i2 = 0;
			while (little[i2] && big[i + i2] == little[i2] && i + i2 < len)
				i2++;
			if (little[i2] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
