/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:59:12 by luhego & parinder #+#    #+#             */
/*   Updated: 2024/01/09 15:19:16 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function switch the current working dir and
	updates therfore the PWD's var in t_env chained list.
*/
int	ft_cd(t_cmd *cmds, t_env *env)
{
	static char	old_pwd[1024];
	static char	pwd[1024];

	if (cmds->prev || cmds->next)
		return (0);
	getcwd(pwd, 1024);
	if (cmds->cmd[1] && (cmds->cmd[2] || chdir(cmds->cmd[1])))
	{
		if (cmds->cmd[2])
			printf("%scd: too many arguments%s\n", RED, RESET);
		return (1);
	}
	ft_strlcpy(old_pwd, pwd, ft_strlen(pwd) + 1);
	ft_env_new(&env, "OLDPWD", old_pwd);
	getcwd(pwd, 1024);
	ft_env_new(&env, "PWD", pwd);
	return (0);
}
