/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:12:42 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 13:20:27 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function print all of its argument seperated by a single ' ' space char.
	if the first arg is == "-n" then skip the newline char at the end.
*/
int	ft_echo(t_cmd *cmds)
{
	int	i;

	i = 1;
	if (cmds->cmd[1] && !ft_strncmp(cmds->cmd[1], "-n", 3))
		i = 2;
	while (cmds->cmd[i])
	{
		write(cmds->fd_out, cmds->cmd[i], ft_strlen(cmds->cmd[i]));
		i++;
		if (cmds->cmd[i])
			write(cmds->fd_out, " ", 1);
	}
	if (!cmds->cmd[1] || ft_strncmp(cmds->cmd[1], "-n", 3))
		write(cmds->fd_out, "\n", 1);
	return (0);
}
