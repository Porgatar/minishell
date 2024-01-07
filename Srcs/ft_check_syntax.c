/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:08:17 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/12 01:22:35 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function check for any redirection syntax error and return 1 if found.
	set *redirection to 1 if the previous token was a redirection and
	0 if it wasn't.
*/
static int	ft_check_redirection(char *token, int *redirection)
{
	if (*redirection)
	{
		if (!token || token[0] == '<' || token[0] == '>' || token[0] == '|')
		{
			printf("%s", RED);
			if (token)
				printf("Minishell: syntax error near unexpected token `%s'", token);
			else
				printf("Minishell: syntax error near unexpected token `newline'");
			printf("%s\n", RESET);
			return (2);
		}
		*redirection = 0;
	}
	else if (token && (token[0] == '<' || token[0] == '>'))
		*redirection = 1;
	return (0);
}

/*
	this function check for any pipe syntax error and return 1 if found.
	set *pipe to 1 if it is the first token or if the previous token was a pipe
	and 0 if it wasn't.
*/
static int	ft_check_pipe(char *token, int *pipe)
{
	if (*pipe)
	{
		if (!token || token[0] == '|')
		{
			printf("%s", RED);
			if (token)
				printf("Minishell: syntax error near unexpected token `%s'", token);
			else
				printf("Minishell: syntax error near unexpected token `newline'");
			printf("%s\n", RESET);
			return (2);
		}
		*pipe = 0;
	}
	else if (token && token[0] == '|')
			*pipe = 1;
	return (0);
}

/*
	this function check if the syntax is correct and return 0,
	return a positive number if it isn't.
*/
int	ft_check_syntax(char **tokens)
{
	int	i;
	int	redirection;
	int	pipe;

	if (!tokens || (tokens && !tokens[0]))
		return (1);
	i = 0;
	redirection = 0;
	pipe = 1;
	while (tokens[i] || redirection || pipe)
	{
		if (ft_check_redirection(tokens[i], &redirection))
			 break ;
		if (ft_check_pipe(tokens[i], &pipe))
			 break ;
		i++;
	}
	if (tokens[i] || redirection || pipe)
	{
		g_status = 2;
		return (2);
	}
	return (0);
}
