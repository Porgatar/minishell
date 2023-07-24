/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:10:26 by parinder          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:54 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1) + 1;
	s2_size = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_size + s2_size));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, s1_size);
	ft_strlcat(str, s2, s1_size + s2_size);
	return (str);
}
