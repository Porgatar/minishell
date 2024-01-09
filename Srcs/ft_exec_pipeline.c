/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2024/01/09 21:30:55 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	All fonction below have to be tested, also need to find how to deal with
	the tab of params cmd/heredoc/redirect/pipe
*/

/*
	this function return an array of all cmd's path from env
*/

static char	*find_path(char *path, char *cmd)
{
	int		path_size;
	int		cmd_size;
	char	*origin_path;

	path_size = ft_strlen(path) + 1;
	cmd_size = ft_strlen(cmd) + 1;
	origin_path = malloc(sizeof(char) * (path_size + cmd_size));
	if (!origin_path)
		return (0);
	origin_path[0] = 0;
	ft_strlcpy(origin_path, path, path_size);
	origin_path[path_size - 1] = '/';
	origin_path[path_size] = '\0';
	ft_strlcpy(&origin_path[path_size], cmd, cmd_size);
	return (origin_path);
}

/*
	this function is here to check if the path is correct,
	in cases he's not the function check if the path can be found
*/
static char	*get_path(char *cmd, t_env *env)
{
	char	**cmd_tab;
	char	*path;
	int		i;

	if (ft_get_env_value("PATH", env) != 0)
		cmd_tab = ft_split(ft_get_env_value("PATH", env)->value, ':');
	else
		cmd_tab = 0;
	if (!cmd_tab)
		return (NULL);
	i = 0;
	while (cmd_tab[i])
	{
		path = find_path(cmd_tab[i], cmd);
		if (access(path, X_OK) == 0)
		{
			ft_free_2dtab(cmd_tab);
			return (path);
		}
		else
			free(path);
		i++;
	}
	ft_free_2dtab(cmd_tab);
	return (NULL);
}

/*
	this function execute the cmd she receive
*/
static void	ft_exec_cmd(t_cmd *cmds, t_env *env)
{
	char	*path;

	dup2(cmds->fd_in, STDIN_FILENO);
	dup2(cmds->fd_out, STDOUT_FILENO);
	ft_close_fds(cmds);
	if (access(cmds->cmd[0], X_OK) == -1 || open(cmds->cmd[0], O_DIRECTORY) > 0)
	{
		path = get_path(cmds->cmd[0], env);
		if (path == NULL)
		{
			g_status = 127;
			if (!access(cmds->cmd[0], F_OK))
				close(3);
			if (!access(cmds->cmd[0], F_OK))
				g_status = 126;
			ft_cmd_clear(cmds);
			ft_env_clear(env);
			exit(g_status);
		}
		free(cmds->cmd[0]);
		cmds->cmd[0] = path;
	}
	execve(cmds->cmd[0], cmds->cmd, 0);
	ft_cmd_clear(cmds);
	ft_exit(0, env);
}

/*
	this function wait the pid of all fork in the launch order,
	update the g_status global var to match exit status and
	print errors in consequences.
*/
static void	ft_waitpid(t_cmd *cmds)
{
	int	status;

	ft_rollback_lst(&cmds);
	while (cmds)
	{
		if (cmds->pid > 0)
			g_status = 0;
		waitpid(cmds->pid, &status, 0);
		status = WEXITSTATUS(status);
		if (!cmds->pid)
			status = 0;
		if (!g_status)
			g_status = status;
		if (g_status == 127)
			printf("%s%s: Command not found%s\n", RED, cmds->cmd[0], RESET);
		else if (g_status == 126)
		{
			if (open(cmds->cmd[0], O_DIRECTORY) && !close(3))
				printf("%s%s: Is a directory%s\n", RED, cmds->cmd[0], RESET);
			else
				printf("%s%s: Permission denied%s\n", RED, cmds->cmd[0], RESET);
		}
		cmds = cmds->next;
	}
}

/*
	this execute all the right cmds in the pipeline
*/
void	ft_exec_pipeline(t_cmd *cmds, t_env **env)
{
	ft_set_sighandler(FORK);
	while (cmds)
	{
		if (!cmds->cmd || !cmds->cmd[0])
			cmds->error = 1;
		if (!cmds->error && !ft_exec_builtins(cmds, env))
		{
			cmds->pid = fork();
			if (cmds->pid == 0)
				ft_exec_cmd(cmds, *env);
		}
		else
			cmds->pid = 0;
		if (cmds->fd_in > 0)
			close(cmds->fd_in);
		if (cmds->fd_out > 1)
			close(cmds->fd_out);
		if (cmds->heredoc > 0)
			close(cmds->heredoc);
		if (!cmds->next)
			break ;
		cmds = cmds->next;
	}
	ft_waitpid(cmds);
	ft_set_sighandler(PROMPT);
}
