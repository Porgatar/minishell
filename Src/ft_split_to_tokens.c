/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:54:29 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/28 15:54:52 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_get_word(const char *s, int id, int *start, int *end)
{
	int	i;
	int	wcount;
	int	quote;

	i = 0;
	wcount = 0;
	while (s[i] && wcount <= id)
	{
		if ((s[i]) && (s[i] == '"' || s[i] == '\''))
		{
			if (start && wcount == id)
				*start = i;
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			i++;
			if (end && wcount == id)
				*end = i;
			wcount++;
		}
		else if (s[i] && !is_space(s[i]))
		{
			if (start && wcount == id)
				*start = i;
			while (s[i] && !is_space(s[i]))
				i++;
			if (end && wcount == id)
				*end = i;
			wcount++;
		}
		else
			i++;
	}
	if (wcount - 1 == id)
		return (1);
	return (0);
}

char	**ft_split_to_tokens(const char *s)
{
	char	**tokens;
	int		wcount;
	int		start;
	int		end;
	int		i;

	wcount = 0;
	while (ft_get_word(s, wcount, 0, 0))
		wcount++;
	tokens = malloc(sizeof(char *) * (wcount + 1));
	if (!tokens)
		return (0);
	tokens[wcount] = 0;
	i = -1;
	while (++i < wcount)
	{
		ft_get_word(s, i, &start, &end);
		tokens[i] = ft_substr(s, start, end - start);
		if (!tokens[i])
		{
			ft_free_2dtab(tokens, i - 1);
			return (0);
		}
	}
	return (tokens);
}

/*	-	-	-	-	-	old split to tokens	-	-	-	-	-

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
*/
