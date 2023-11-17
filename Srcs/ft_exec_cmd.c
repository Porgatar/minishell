/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/11/17 21:24:06 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
All fonction below have to be tested, also need to find how to deal with the tab of params
cmd/heredoc/redirect/pipe
*/

/* - - - this function return an array of all cmd's path from env - - -*/

static char	*find_path(char *path, char *cmd)
{
	int		path_size;
	int		cmd_size;
	char	*origin_path;

	path_size = ft_strlen(path) + 1;
	cmd_size = ft_strlen(cmd) + 1;
	origin_path = malloc(sizeof(char) * (path_size + cmd_size));
	if (!origin_size)
	{
		perrir("path");
		return (0);
	}
	origin_path[0] = 0;
	ft_strlcat(origin_path, path_lst, path_size);
	origin_path[path_size - 1] = '/';
	origin_path[path_size] = '\0';
	ft_strlcat(origin_path, cmd, path_size, cmd_size);
	return (origin_path);
}

/* - - - this function is here to check if the path is correct, in cases he's not the function check if the path can be found - - - */

static char	*get_path(t_env *env, char *cmd)
{
	char	**cmd_tab;
	char	*path;
	int		i;

	cmd_tab = ft_split(ft_get_env_value("PATH", env), ':');
	if (!cmd_tab)
		return (NULL);
	i = 0;
	while(cmd_tab[i])
	{
		path = find_path(cmd_tab[i], cmd);
		if (access([path, X_OK]) == 0)
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

/* - - - this function execute the cmd that he receive - - - */

static void	ft_exec_cmd(char **cmd)
{
	if (access(cmd[0], X_OK) == -1)
	{
		path = get_path(env, cmd[0]);
		if (path == NULL)
		{
			ft_putstr_fd("command not found:\n", 2);
			ft_free_2tab(cmd);
			exit(0);
		}
		free(cmd[0]);
		cmd[0] = path;
	}
	execve(cmd[0], &cmd[0], env);
	ft_free_2dtab(cmd);
}

/* - - - this funtion run a sous-process and follow send cmd to be executed in the same order as bash do it - - - */

void	run_process(int pipe, )
{
	int	fd;

	if (cmd == cmd[0])
		fd = open(frist_cmd, O_RDONLY);
	else if (cmd == cmd[last])
		fd = open(last_cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
	if (fd == -1)
	{
		perror(cmd);
		close(pipe[0]);
		close(pipe[1]);
		exit(0);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipe[1])

}

/* - - - this function create sous-process that run and execute cmd's one after an other as bash do it - - - */

void	pipex_minishell(t_cmd cmd, int fd, char **env)
{
	int	pipe[2];
	int	pipe2[2];
	pid_t	pid;

	if (pipe(pipe) == -1)
	{
		write(1, "pipe, error\n", 12);
		exit(0);
	}
	while (nb_pipe > 1)
	{
		fd = open(first_cmd, O_RDONLY);
		if (pipe(p) == -1)
		{
			write(1, "pipe, error", 12);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
			run_process(pipe, fd, env);
		close(p[0]);
		close(p[1]);
		waitpid(pid, 0, 0);  // to rm ??
	}
	fd = open(last_cmd, O_WRONLY | O_TRUNC O_CREAT, 00644);
	pid = fork();
	if (pid == 0)
		run_process(pipe, fd, env); // last process
	close(p[0]);
	close(p[1]);
	waitpid(pid, 0 , 0); /* rm other waitpid ?*/
}
