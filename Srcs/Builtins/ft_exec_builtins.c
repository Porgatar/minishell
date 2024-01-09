/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:43 by luhego & parinder #+#    #+#             */
/*   Updated: 2024/01/09 21:34:45 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function execute the corresponding builtins if it is one
	and return 1, return 0 if it isn't one.
*/
int	ft_exec_builtins(t_cmd *cmds, t_env **env)
{
	int	exit;

	if (!ft_strncmp(cmds->cmd[0], "echo", 5))
		exit = ft_echo(cmds);
	else if (!ft_strncmp(cmds->cmd[0], "cd", 3))
		exit = ft_cd(cmds, *env);
	else if (!ft_strncmp(cmds->cmd[0], "pwd", 4))
		exit = ft_pwd(cmds);
	else if (!ft_strncmp(cmds->cmd[0], "export", 7))
		exit = ft_export(cmds, *env);
	else if (!ft_strncmp(cmds->cmd[0], "unset", 6))
		exit = ft_unset(cmds, env);
	else if (!ft_strncmp(cmds->cmd[0], "env", 4))
		exit = ft_env(cmds, *env);
	else if (!ft_strncmp(cmds->cmd[0], "exit", 5))
		exit = ft_exit(cmds, *env);
	else
		return (0);
	g_status = exit;
	return (1);
}
