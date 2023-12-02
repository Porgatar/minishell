/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:32:18 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 13:18:48 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 

/*
	this function close all the opend fd in the chained list of cmds.
*/
void	ft_close_fds(t_cmd *cmds)
{
	while (cmds)
	{
		if (cmds->fd_in > 0)
			close(cmds->fd_in);
		if (cmds->fd_out > 1)
			close(cmds->fd_out);
		cmds = cmds->next;
	}
}

/*
	.
	142 = heredoc.
*/
static void	ft_redirect_in(t_cmd *cmds, int i)
{
	if (cmds->fd_in > 0)
		close(cmds->fd_in);
	if (!strncmp(cmds->cmd[i], "<", 2))
	{
		cmds->fd_in = open(cmds->cmd[i + 1], O_RDONLY);
		if (cmds->fd_in == -1)
			return ;
	}
	else if (!strncmp(cmds->cmd[i], "<<", 3))
	{
		cmds->fd_in = 142;
		if (cmds->fd_in == -1)
			return ;
	}
}

/*

*/
static void	ft_redirect_out(t_cmd *cmds, int i)
{
	if (cmds->fd_out > 1)
		close(cmds->fd_out);
	if (!strncmp(cmds->cmd[i], ">", 2))
	{
		cmds->fd_out = open(cmds->cmd[i + 1], \
		O_WRONLY | O_TRUNC | O_CREAT, 00644);
		if (cmds->fd_out == -1)
			return ;
	}
	else if (!strncmp(cmds->cmd[i], ">>", 3))
	{
		cmds->fd_out = open(cmds->cmd[i + 1], \
		O_WRONLY | O_APPEND | O_CREAT, 00644);
		if (cmds->fd_out == -1)
			return ;
	}
}

/*

*/
void	ft_redirect(t_cmd *cmds)
{
	int	i;
	int	fd[2];

	while (cmds)
	{
		if (!cmds->prev)
			cmds->fd_in = 0;
		cmds->fd_out = 1;
		if (cmds->next)
		{
			pipe(fd);
			cmds->next->fd_in = fd[0];
			cmds->fd_out = fd[1];
		}
		i = 0;
		while (cmds->cmd[i])
		{
			if (cmds->cmd[i][0] == '<')
				ft_redirect_in(cmds, i);
			else if (cmds->cmd[i][0] == '>')
				ft_redirect_out(cmds, i);
			i++;
		}
		cmds = cmds->next;
	}
}
