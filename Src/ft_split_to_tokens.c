/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:54:29 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/26 19:04:41 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static void	ft_wcount(const char *s, int *wcount)
{
	int	i;
	int	quote;

	*wcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if ((s[i]) && (s[i] == '"' || s[i] == '\''))
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			i++;
			*wcount += 1;
		}
		if (s[i] && s[i] != ' ')
		{
			while (s[i] && s[i] != ' ')
				i++;
			*wcount += 1;
		}
	}
}

static int	ft_wlen(const char *s, int word)
{
	int	i;
	int	wcount;
	int	wlen;
	int	quote;

	i = 0;
	wcount = 0;
	wlen = 0;
	while (s[i] && wlen == 0)
	{
		while (s[i] && s[i] == ' ')
			i++;
		if ((s[i]) && (s[i] == '"' || s[i] == '\''))
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
			{
				if (s[i] && wcount == word)
					wlen++;
				i++;
			}
			i++;
			if (s[i] && wcount == word)
				wlen += 2;
			wcount++;
		}
		else if (s[i] && s[i] != ' ')
		{
			while (s[i] && s[i] != ' ')
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

static void	ft_strscpy(char **strs, const char *s)
{
	int	i;
	int	y;
	int	wcount;
	int	quote;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if ((s[i]) && (s[i] == '"' || s[i] == '\''))
		{
			quote = s[i++];
			y = 0;
			while (s[i] && s[i] != quote)
			{
				strs[wcount][y] = s[i];
				i++;
				y++;
			}
			strs[wcount][y] = 0;
			wcount++;
		}
		if (s[i] && s[i] != ' ')
		{
			y = 0;
			while (s[i] && s[i] != ' ')
			{
				strs[wcount][y] = s[i];
				i++;
				y++;
			}
			strs[wcount][y] = 0;
			wcount++;
		}
	}
}

char	**ft_split_to_tokens(const char *str)
{
	char	**tokens;
	int		wcount;
	int		i;

	ft_wcount(str, &wcount);
	printf("wcount = %d\n", wcount);
	tokens = malloc(wcount + 1 * sizeof(char *));
	if (!tokens)
		return (0);
	i = 0;
	while (i < wcount)
	{
		tokens[i] = malloc(ft_wlen(str, i) + 1 * sizeof(char));
		if (!tokens[i])
		{
			ft_free_2dtab(tokens, i - 1);
			return (0);
		}
		i++;
	}
	ft_strscpy(tokens, str);
	tokens[i] = 0;
	return (tokens);
}
