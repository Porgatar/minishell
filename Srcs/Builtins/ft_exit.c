/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:56:49 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 18:07:53 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_exit(t_cmd *cmds, t_env *env)
{
	if (!cmds->next && !cmds->prev)
	{
		ft_env_clear(env);
		ft_cmd_clear(cmds);
		write(1, "exit\n", 5);
		exit(0);
	}
	return (-1);
}
