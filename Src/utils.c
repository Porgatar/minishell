/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:29:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/27 23:29:47 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

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

int	is_space(char c)
{
	if ((c > 8 && c < 14) || (c == ' '))
		return (1);
	return (0);
}

void	ft_free_2dtab(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}
