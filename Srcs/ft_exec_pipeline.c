/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/11 18:53:40 by parinder         ###   ########.fr       */
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
	{
		printf(RED);
		perror("path");
		printf(RESET);
		return (0);
	}
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

	cmd_tab = ft_split(ft_get_env_value("PATH", env)->value, ':');
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
	if (access(cmds->cmd[0], X_OK) == -1)
	{
		path = get_path(cmds->cmd[0], env);
		if (path == NULL)
		{
			printf("%s%s : command not found !\n%s", RED, cmds->cmd[0], RESET);
			ft_cmd_clear(cmds);
			ft_env_clear(env);
			exit(127);
		}
		free(cmds->cmd[0]);
		cmds->cmd[0] = path;
	}
	execve(cmds->cmd[0], cmds->cmd, 0);
	ft_cmd_clear(cmds);
	ft_env_clear(env);
	exit(g_status);
}

/*

*/
void	ft_exec_pipeline(t_cmd *cmds, t_env *env)
{
	pid_t	pid;
	int		status;

	g_status = 0;
	ft_set_sighandler(FORK);
	while (cmds)
	{
		if (!ft_exec_builtins(cmds, env))
		{
			pid = fork();
			if (pid == 0)
				ft_exec_cmd(cmds, env);
		}
		if (cmds->fd_in != 0)
			close(cmds->fd_in);
		if (cmds->fd_out != 1)
			close(cmds->fd_out);
		cmds = cmds->next;
	}
	waitpid(0, &status, 0);
	status = WEXITSTATUS(status);
	if (!g_status)
		g_status = status;
	ft_set_sighandler(PROMPT);
}
