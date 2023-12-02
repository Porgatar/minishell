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
int	ft_cd(t_cmd *cmds)
{
	if (cmds->cmd[2])
	{
		printf("cd: too may arguments\n");
	}
	chdir(cmds->cmd[1]);
	return (0);
}
