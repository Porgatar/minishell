/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:43 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/01 19:05:06 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_exec_builtins(t_cmd *cmds, t_env *env)
{
	if (ft_strncmp(cmds->cmd[0], "echo", 5))
		ft_echo(cmds);
//	else if (ft_strncmp(cmds->cmd[0], "cd", 3))
//		ft_cd(cmds);
	else if (ft_strncmp(cmds->cmd[0], "pwd", 4))
		ft_pwd(cmds);
	else if (ft_strncmp(cmds->cmd[0], "export", 7))
		ft_export(cmds, env);
//	else if (ft_strncmp(cmds->cmd[0], "unset", 6))
//		ft_unset(cmds);
	else if (ft_strncmp(cmds->cmd[0], "env", 4))
		ft_env(cmds, env);
//	else if (ft_strncmp(cmds->cmd[0], "exit", 5))
//		ft_exit(cmds);
	else
		return (0);
	return (1);
}
