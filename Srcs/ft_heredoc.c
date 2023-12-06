/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:47:33 by parinder          #+#    #+#             */
/*   Updated: 2023/12/05 22:25:34 by parinder         ###   ########.fr       */
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
	.
*/
int	ft_heredoc(t_cmd *cmds, int i)
{
	int	fd[2];

	pipe(fd);
	cmds->cmd[i + 1] = ft_unquote(cmds->cmd[i + 1]);
	printf("> ");
	while ()
	{

		if ()
	}
	return (0);
}
