/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:47:33 by parinder          #+#    #+#             */
/*   Updated: 2023/12/07 00:05:54 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function unquote the word and return a pointer to the new string
	created without quote.
*/
static char	*ft_unquote(char *word)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (word[++i])
		if (word[i] != '\'' && word[i] != '"')
			len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	len = 0;
	while (word[++i])
	{
		if (word[i] != '\'' && word[i] != '"')
		{
			str[len] = word[i];
			len++;
		}
	}
	str[len] = 0;
	return (str);
}

/*
	this function create a pipe that hear out the terminal to fill it and
	return a O_RDONLY fd to it.
*/
int	ft_heredoc(t_cmd *cmds, int i)
{
	int		fd[2];
//	char	*str;

	pipe(fd);
	cmds->cmd[i + 1] = ft_unquote(cmds->cmd[i + 1]);
//	while (1)
//	{
//		str = readline("> ");
//		if ()
//	}
	return (0);
}
