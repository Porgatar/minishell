/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:51:12 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/12 02:33:16 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	copies and return the number of token for the current cmd.
*/
static int	ft_get_cmd(char **tokens, t_cmd **cmds, t_cmd *prev)
{
	int	i;
	int	j;
	int	is_pipe;

	i = 0;
	is_pipe = 0;
	if (tokens[0][0] == '|')
	{
		is_pipe = 1;
		free(tokens[0]);
	}
	while (tokens[i + is_pipe] && tokens[i + is_pipe][0] != '|')
		i++;
	(*cmds)->cmd = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (j < i)
	{
		(*cmds)->cmd[j] = tokens[j + is_pipe];
		j++;
	}
	(*cmds)->error = 0;
	(*cmds)->cmd[j] = 0;
	(*cmds)->prev = prev;
	(*cmds)->next = 0;
	return (i + is_pipe);
}

/*
	the purpose of this function is to parse the tokens into
	a chained list of simple and compund commands.
*/
t_cmd	*ft_parse_to_cmds(char **tokens)
{
	t_cmd	*prev;
	t_cmd	*cmds;
	int		i;

	cmds = malloc(sizeof(t_cmd));
	prev = 0;
	i = 0;
	while (tokens[i])
	{
		if (!cmds)
		{
			ft_cmd_clear(cmds);
			return (0);
		}
		i += ft_get_cmd(&tokens[i], &cmds, prev);
		if (tokens[i])
		{
			prev = cmds;
			cmds->next = malloc(sizeof(t_cmd));
			cmds = cmds->next;
		}
	}
	ft_rollback_lst(&cmds);
	free(tokens);
	return (cmds);
}
