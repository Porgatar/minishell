/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:56:49 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/11 16:55:40 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_exit(t_cmd *cmds, t_env *env)
{
	if (!cmds)
	{
		ft_env_clear(env);
		printf("\n");
		exit(g_status);
	}
	else if (!cmds->next && !cmds->prev)
	{
		ft_env_clear(env);
		ft_cmd_clear(cmds);
		printf("exit\n");
		exit(g_status);
	}
	return (-1);
}
