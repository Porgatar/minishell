/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:43 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/11/24 19:07:17 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_exec_builtins(t_cmd *cmds)
{
	if (ft_strncmp(cmds->cmd, "echo", 5))
		ft_echo(cmds);
	else if (ft_strncmp(cmds->cmd, "cd", 3))
		ft_cd(cmds);
	else if (ft_strncmp(cmds->cmd, "pwd", 4))
		ft_pwd(cmds);
	else if (ft_strncmp(cmds->cmd, "export", 7))
		ft_export(cmds);
	else if (ft_strncmp(cmds->cmd, "unset", 6))
		ft_unset(cmds);
	else if (ft_strncmp(cmds->cmd, "env", 4))
		ft_env(cmds);
	else if (ft_strncmp(cmds->cmd, "exit", 5))
		ft_exit(cmds);
	else
		return (0);
	return (1);
}
