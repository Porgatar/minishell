/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:17:49 by parinder          #+#    #+#             */
/*   Updated: 2023/12/01 17:50:36 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
static void	ft_order_env()
{
	
}
*/

static int	ft_display_export(t_cmd *cmds, t_env *env)
{
	while (env)
	{
		write(cmds->fd_out, "declare -x ", 1);
		write(cmds->fd_out, env->key, ft_strlen(env->key));
		write(cmds->fd_out, "=\"", 2);
		write(cmds->fd_out, env->value, ft_strlen(env->value));
		write(cmds->fd_out, "\"\n", 2);
		env = env->next;
	}
	return (0);
}

/*
	ft_export displays the env chained list in alphabetik order if no args are sent,
	but set a new or already set variable to a new value for all args sent.
*/
int	ft_export(t_cmd *cmds, t_env *env)
{
	int	i;

	if (!cmds->cmd[1])
	{
		ft_display_export(cmds, env);
		return (0);
	}
	i = 0;
	while (cmds->cmd[i])
	{
		
		i++;
	}
	return (0);
}
