/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:47:33 by parinder          #+#    #+#             */
/*   Updated: 2023/12/05 18:55:21 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
static void	ft_unquote(char **word)
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
		return ;
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
}
*/
int	ft_heredoc(t_cmd *cmds, int i)
{
//	int	fd[2];
/*
	pipe(fd);
	ft_unquote(&cmds->cmd[i + 1])
*/	(void)cmds;
	(void)i;
	return (0);
}
