/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:54:29 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/31 15:33:14 by parinder         ###   ########.fr       */
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
			if (!s[i])
				return (-1);
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

static char	**ft_init_wcount(const char *s, int *wcount)
{
	char	**tokens;

	if (ft_get_word(s, 2147483647, 0, 0) == -1)
	{
		printf("%sError: a quote is not closed !%s\n", RED, RESET);
		return (0);
	}
	*wcount = 0;
	while (ft_get_word(s, *wcount, 0, 0))
		*wcount += 1;
	tokens = malloc(sizeof(char *) * (*wcount + 1));
	if (!tokens)
	{
		printf("%s", RED);
		perror("tokens spliting");
		printf("%s", RESET);
		return (0);
	}
	tokens[*wcount] = 0;
	return (tokens);
}

char	**ft_split_to_tokens(const char *s)
{
	char	**tokens;
	int		wcount;
	int		start;
	int		end;
	int		i;

	tokens = ft_init_wcount(s, &wcount);
	if (!tokens)
		return (0);
	i = -1;
	while (++i < wcount)
	{
		ft_get_word(s, i, &start, &end);
		tokens[i] = ft_substr(s, start, end - start);
		if (!tokens[i])
		{
			ft_free_2dtab(tokens, i - 1);
			printf("%s", RED);
			perror("tokens spliting");
			printf("%s", RESET);
			return (0);
		}
	}
	return (tokens);
}
