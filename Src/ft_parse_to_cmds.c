/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:51:12 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/02 17:01:26 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_get_cmd(char **tokens, t_cmd **cmds)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i] && tokens[i][0] != '|' && tokens[i][0] != '<' && tokens[i][0] != '>')
		i++;
	if (tokens[0][0] == '<' || tokens[0][0] == '>')
		i = 2;
	else if (tokens[0][0] == '|')
		i = 1;
	(*cmds)->cmd = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (j < i)
	{
		(*cmds)->cmd[j] = tokens[j];
		j++;
	}
	(*cmds)->cmd[j] = 0;
	return (i);
}

t_cmd	*ft_parse_to_cmds(char **tokens)
{
	t_cmd	*first_cmd;
	t_cmd	*cmds;
	int		i;

	cmds = malloc(sizeof(t_cmd));
	first_cmd = cmds;
	i = 0;
	while(tokens[i])
	{
		if (!cmds)
		{
			printf("%sError: not enough memory%s\n", RED, RESET);
			ft_lst_clear(&first_cmd);
			return (0);
		}
		i += ft_get_cmd(&tokens[i], &cmds);
		if (tokens[i])
		{
			cmds->next = malloc(sizeof(t_cmd));
			cmds = cmds->next;
		}
	}
	cmds->next = 0;
	return (first_cmd);
}
