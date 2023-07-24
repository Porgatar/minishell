/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:17:10 by parinder          #+#    #+#             */
/*   Updated: 2022/10/08 16:14:49 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		slen;

	slen = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * slen);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s, slen);
	return (str);
}
