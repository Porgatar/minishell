/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:54:29 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/26 22:40:15 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

/*
static int	ft_get_word(const char *s, int id, int *start, int *len)
{
	int	i;
	int	wcount;
	int	quote;

	i = -1;
	wcount = 0;
	*start = 0;
	*len = 0;
	while (s[++i] && wcount <= id)
	{
		if ((s[i]) && (s[i] == '"' || s[i] == '\''))
		{
			if (wcount == id)
				*start = i;
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (wcount == id)
				*len = i;
			wcount++;
		}
		else if (s[i] && !is_space(s[i]))
		{
			if (wcount == id)
				*start = i;
			while (s[i] && is_space(s[i]))
				i++;
			if (wcount == id)
				*len = i;
			wcount++;
		}
	}
	if (wcount - 1 == id)
		return (1);
	return (0);
}

char	**ft_split_to_tokens(const char *s)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (ft_get_word(s, ++i, &start, &end))
	{
		printf("start = %d, ", start);
		printf("end = %d\n", end);
		printf("i = %d, \"%s\"\n", i, &s[start]);
	}
	return (0);
}

*/
///*
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
			quote = s[i];
			y = 0;
			strs[wcount][y] = s[i++];
			while (s[i] && s[i] != quote)
			{
				strs[wcount][y] = s[i];
				i++;
				y++;
			}
			strs[wcount][y] = s[i++];
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
	tokens = malloc(sizeof(char *) * (wcount + 1));
	if (!tokens)
		return (0);
	i = 0;
	while (i < wcount)
	{
		tokens[i] = malloc(sizeof(char) * (ft_wlen(str, i) + 1));
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
//*/
