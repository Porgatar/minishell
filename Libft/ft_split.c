/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:13:50 by parinder          #+#    #+#             */
/*   Updated: 2022/10/06 13:08:12 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wcount(const char *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			wcount++;
		}
	}
	return (wcount);
}

static int	ft_wlen(const char *s, char c, int word)
{
	int	i;
	int	wcount;
	int	wlen;

	i = 0;
	wcount = 0;
	wlen = 0;
	while (s[i] && wlen == 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				if (s[i] && wcount == word)
					wlen++;
				i++;
			}
			wcount++;
		}
	}
	return (wlen);
}

static void	ft_strscpy(char **strs, const char *s, char c)
{
	int	i;
	int	i2;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			i2 = 0;
			while (s[i] && s[i] != c)
			{
				strs[wcount][i2] = s[i];
				i++;
				i2++;
			}
			strs[wcount][i2] = 0;
			wcount++;
		}
	}
}

static void	ft_free_2dtab(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wcount;
	int		i;

	if (!s)
		return (0);
	wcount = ft_wcount(s, c);
	strs = ft_calloc(wcount + 1, sizeof(char *));
	if (!strs)
		return (0);
	i = 0;
	while (i < wcount)
	{
		strs[i] = ft_calloc(ft_wlen(s, c, i) + 1, sizeof(char));
		if (!strs[i])
		{
			ft_free_2dtab(strs, i - 1);
			return (0);
		}
		i++;
	}
	ft_strscpy(strs, s, c);
	return (strs);
}
