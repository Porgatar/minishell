/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:59:12 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 21:47:10 by luhego           ###   ########.fr       */
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

	if (cmds->cmd[2])
		printf("cd: too many arguments\n");
	ft_strlcpy(old_pwd, pwd, ft_strlen(pwd));
	if (!ft_get_env_value("OLDPWD", env))
		ft_env_new(&env, "OLDPWD", old_pwd);
	chdir(cmds->cmd[1]);
	getcwd(pwd, 1024);
	/*nset(pwd);
	getcwd(pwd, pwd[1024]);
	ft_env_new(&env, "PWD", pwd);
	*/return (0);
}
