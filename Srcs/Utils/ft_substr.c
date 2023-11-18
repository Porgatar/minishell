/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:44:33 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/11/18 16:38:07 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	strlen;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (strlen < start)
		return (malloc(sizeof(char) * 1));
	if (strlen - start < len)
		len = strlen - start;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (0);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
