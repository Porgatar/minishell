/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/01 17:42:41 by luhego           ###   ########.fr       */
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
	if (!origin_path)
	{
		perror("path");
		return (0);
	}
	origin_path[0] = 0;
	ft_strlcpy(origin_path, path, path_size);
	origin_path[path_size - 1] = '/';
	origin_path[path_size] = '\0';
	ft_strlcpy(&origin_path[path_size], cmd, cmd_size);
	printf("path = \"%s\"\n", origin_path);
	return (origin_path);
}

/* - - - this function is here to check if the path is correct, in cases he's not the function check if the path can be found - - - */

static char	*get_path(char *cmd, t_env *env)
{
	char	**cmd_tab;
	char	*path;
	int		i;

	cmd_tab = ft_split(ft_get_env_value("PATH", env)->value, ':');
	if (!cmd_tab)
		return (NULL);
	i = 0;
	while(cmd_tab[i])
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

static void ft_free_redirect(char **redirect)
{
	int	i;

	i = 0;
	while (redirect[i])
	{
		free(redirect[i]);
		i++;
	}
	*redirect = 0;
}

/* - - - this function execute the cmd she receive - - - */

void	ft_exec_cmd(t_cmd *cmds, t_env *env)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	while (cmds->cmd[i] && (cmds->cmd[i][0] == '<' || cmds->cmd[i][0] == '>'))
		i += 2;
	j = i;
	while (cmds->cmd[j] && cmds->cmd[j][0] != '<' && cmds->cmd[j][0] != '>')
		j++;
	ft_free_redirect(&cmds->cmd[j]);
	printf("%s\n", cmds->cmd[i]);
	if (access(cmds->cmd[i], X_OK) == -1)
	{
		path = get_path(cmds->cmd[i], env);
		if (path == NULL)
		{
			printf("command not found:\n");
		//	ft_free_2dtab(cmds->cmd[0]);
			exit(0);
		}
		free(cmds->cmd[i]);
		cmds->cmd[i] = path;
	}
	execve(cmds->cmd[i], &cmds->cmd[i], 0);
	// free();
}

void	ft_set_process(t_cmd *cmds, t_env *env)
{
	pid_t	pid;

	while(cmds)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(cmds->fd_in, STDIN_FILENO);
			dup2(cmds->fd_out, STDOUT_FILENO);
			close(cmds->fd_in);
			close(cmds->fd_out);
			ft_exec_cmd(cmds, env);
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
		}
		cmds = cmds->next;
	}
}
