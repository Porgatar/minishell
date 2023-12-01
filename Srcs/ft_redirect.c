/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:32:18 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/01 17:58:23 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 

/*

*/
void	ft_redirect_in(t_cmd *args, int i)
{
	if (args->fd_in > 0)
		close(args->fd_in);
	if (!strncmp(args->cmd[i], "<", 2))
	{
		args->fd_in = open(args->cmd[i + 1], O_RDONLY);
		if (args->fd_in == -1)
			return ;
	}
	else if (!strncmp(args->cmd[i], "<<", 3))
	{
		args->fd_in = 142; // heredoc
		if (args->fd_in == -1)
			return ;
	}
}
/*

*/
void	ft_redirect_out(t_cmd *args, int i)
{
	if (args->fd_out > 1)
		close(args->fd_out);
	if (!strncmp(args->cmd[i], ">", 2))
	{
		args->fd_out = open(args->cmd[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 00644);
		if (args->fd_out == -1)
			return ;
	}
	else if (!strncmp(args->cmd[i], ">>", 3))
	{
		args->fd_out = open(args->cmd[i + 1], O_WRONLY | O_APPEND | O_CREAT, 00644);
		if (args->fd_out == -1)
			return ;
	}
}
/*

*/
void	ft_redirect(t_cmd *args)
{
	int	i;
	int	fd[2];

	while (args)
	{
		args->fd_in = 0;
		args->fd_out = 1;
		if (args->next)
		{
			pipe(fd);
			args->next->fd_in = fd[0];
			args->fd_out = fd[1];
		}
		i = 0;
		while (args->cmd[i])
		{
			if (args->cmd[i][0] == '<')
				ft_redirect_in(args, i);
			else if (args->cmd[i][0] == '>')
				ft_redirect_out(args, i);
			i++;
		}
		args = args->next;
	}
}
