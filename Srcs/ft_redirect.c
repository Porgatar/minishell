/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:32:18 by parinder & luhego #+#    #+#             */
/*   Updated: 2023/11/23 18:33:23 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_redirect(t_cmd *args)
{
	if (!strncmp(args->cmd[1], "<", 2))
	{
		args->fd_in = open(args->cmd[i + 1], O_RDONLY)
		if (args->fd_in == -1)
			return ;
	}
	else if (!strncmp(args->cmd[i], ">", 2))
	{
		args->fd_out = open(args->cnd[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 00644);
		if (args->fd_out = -1)
			return ;
	}
	else if (!strncmp(args->cmd[1], "<<", 3))
	{
		args->fd_in = /* ft_heredoc */;
		if (args->fd_in == -1)
			return ;
	}
	else if (!strncmp(args->cmd[1], ">>", 3))
	{
		args->fd_out = open(args->cmd[i + 1], O_WRONLY | O_APPEND | O_CREAT, 00644);
		if (args->fd_out == -1)
			return ;
	}
}

void	ft_check_redirect(t_cmd args, t_env *env)
{
	int	i;

	while (args)
	{
		i = 0;
		while (args->cmd[i])
		{
		//	if (args->cmd[i - 1]->fd_in)
				close(args->cmd[i - 1]->fd_in);
			if (args->fd_out)
				close(args->fd_out);
			if (args->cmd[i][0] == '>' || args->cmd[i][0] == '<')
				ft_redirect(args);
			else
				minish_pipex(args);
			i++;
		}
		args = args->next;
	}
}

void	minish_pipex(tt_cmd args)
{
	int pipes[2];
	if (pipe(pipes) == -1)
	{
		perror();
		return ;
	}
	fork();
	while (cmd == true)
	{
		dup2(pipe[1], std_in);
		dup2(pipe[2], std_out);
		if (pid == 0)
			ft_run_child_process(args->cmd[x], args->fd_in[x], args->fd_out[x]);
		cmd = cmd->next;
	}
}
