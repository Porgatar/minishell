/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:56:49 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/09 22:05:09 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exitshell(const char *error)
{
	if (!error)
		write(1, "exit\n", 5);
	if (errno)
		perror(error);
	exit(errno);
}

int	ft_exit(t_cmd *cmds, t_env *env)
{
	if (!cmds->next && !cmds->prev)
	{
		ft_env_clear(env);
		ft_cmd_clear(cmds);
		ft_exitshell(0);
	}
	return (-1);
}
