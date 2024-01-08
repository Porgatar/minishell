/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:56:49 by luhego & parinder #+#    #+#             */
/*   Updated: 2024/01/08 12:56:50 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function calculate the exit status and return it.
*/
static int	ft_exit_status(t_cmd *cmds, t_env *env)
{
	if (!cmds->next && !cmds->prev)
	{
		if (cmds->cmd[1])
			g_status = ft_atoi(cmds->cmd[1]);
		else
			g_status = 0;
		if (cmds->cmd[1] && cmds->cmd[1][0] != '0' && !g_status)
		{
			printf("%sminishell: exit: %s: numeric arguments required%s\n", \
			RED, cmds->cmd[1], RESET);
			ft_env_clear(env);
			ft_cmd_clear(cmds);
			exit(2);
		}
		if (cmds->cmd[1] && cmds->cmd[2])
		{
			printf("%sminishell: exit: too many arguments%s\n", RED, RESET);
			return (1);
		}
		printf("exit\n");
		ft_env_clear(env);
		ft_cmd_clear(cmds);
		exit(g_status);
	}
	return (0);
}

/*
	this function terminate the minishell prompt.
*/
int	ft_exit(t_cmd *cmds, t_env *env)
{
	if (!cmds)
	{
		ft_env_clear(env);
		printf("\n");
		exit(g_status);
	}
	return (ft_exit_status(cmds, env));
}
