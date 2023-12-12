/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:32:18 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/12 01:59:42 by parinder         ###   ########.fr       */
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
	this function delete the redirections strings of the tab.
*/
static void	ft_delstr(t_cmd *cmds, int i)
{
	if (cmds->cmd[i] && cmds->cmd[i + 1])
	{
		free(cmds->cmd[i]);
		free(cmds->cmd[i + 1]);
	}
	while (cmds->cmd[i + 2])
	{
		cmds->cmd[i] = cmds->cmd[i + 2];
		i++;
	}
	cmds->cmd[i] = 0;
	cmds->cmd[i + 1] = 0;
}

/*
	this function check if a redirection error occured
	and set cmds->error code to 1 in consequences.
*/
static void	ft_check_redirect_error(t_cmd *cmds, int i)
{
	if (cmds->fd_in == -1 || cmds->fd_out == -1)
	{
		cmds->error = 1;
		printf(RED);
		printf("minishell: %s: No such file or directory\n", cmds->cmd[i + 1]);
		printf(RESET);
	}
}

/*

*/
static void	ft_open(t_cmd *cmds, int i, t_env *env)
{
	if (!cmds->error && cmds->cmd[i][0] == '>' && cmds->fd_out != -1)
	{
		if (cmds->fd_out > 1)
			close(cmds->fd_out);
		if (!strncmp(cmds->cmd[i], ">", 2))
			cmds->fd_out = open(cmds->cmd[i + 1], \
			O_WRONLY | O_TRUNC | O_CREAT, 00644);
		else
			cmds->fd_out = open(cmds->cmd[i + 1], \
			O_WRONLY | O_APPEND | O_CREAT, 00644);
	}
	if (!cmds->error && cmds->cmd[i][0] == '<' && cmds->fd_in != -1)
	{
		if (cmds->fd_in > 0)
			close(cmds->fd_in);
		if (!strncmp(cmds->cmd[i], "<", 2))
			cmds->fd_in = open(cmds->cmd[i + 1], O_RDONLY);
		else
			cmds->fd_in = ft_heredoc(cmds, i, env);
	}
	if (!cmds->error)
		ft_check_redirect_error(cmds, i);
	ft_delstr(cmds, i);
}

/*

*/
void	ft_redirect(t_cmd *cmds, t_env *env)
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
			if (cmds->cmd[i][0] == '<' || cmds->cmd[i][0] == '>')
				ft_open(cmds, i, env);
			else
				i++;
		}
		cmds = cmds->next;
	}
}
