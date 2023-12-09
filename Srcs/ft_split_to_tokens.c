/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:54:29 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/09 22:22:04 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function represente the loop in ft_get_word,
	it is needed to split the tokens and the special chars
*/
static int	ft_in_loop(const char *s, int i)
{
	int	quote;

	if (s[i] == '|' || s[i] == '<' || s[i] == '>')
	{
		quote = s[i++];
		if (s[i] && s[i] == quote)
			i++;
		return (i);
	}
	while (s[i] && !is_space(s[i]))
	{
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			break ;
		if ((s[i]) && (s[i] == '"' || s[i] == '\''))
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (!s[i])
				return (-1);
		}
		i++;
	}
	return (i);
}

/*
	this fuction set respectively the pointer '*start' and '*end'
	to the start and end of the found token.
	return 1 on succes, 0 when the token 'id' has been not found and
	-1 if a non closed quote is detected.
*/
static int	ft_get_word(const char *s, int id, int *start, int *end)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i] && wcount <= id)
	{
		if (s[i] && !is_space(s[i]))
		{
			if (start && wcount == id)
				*start = i;
			i = ft_in_loop(s, i);
			if (i == -1)
				return (-1);
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

/*
	return a malloc and set *wcount to the number of words(tokens) detected.
*/
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
		printf("%sError: not enough memory%s\n", RED, RESET);
		return (0);
	}
	tokens[*wcount] = 0;
	return (tokens);
}

/*
	the purpose of this function is to split 's' into "tokens"(*see below)
	with the help of all the above static functions.
	return a pointer on the splited tab or 0 if any error occurs.

	*	tokens
		can be an arbitrary number of char seperated by whitespace or between quotes.
*/
char	**ft_split_to_tokens(char *s)
{
	char	**tokens;
	int		wcount;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (0);
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
			ft_free_2dtab(tokens);
			return (0);
		}
	}
	free(s);
	return (tokens);
}
