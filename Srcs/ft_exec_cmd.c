/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/11/18 17:36:55 by parinder         ###   ########.fr       */
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

static char	*get_path(t_env *env, char *cmd)
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

/* - - - this function execute the cmd that he receive - - - */

void	ft_exec_cmd(char **cmd, t_env *env)
{
	char	*path;

	if (access(cmd[0], X_OK) == -1)
	{
		path = get_path(env, cmd[0]);
		if (path == NULL)
		{
			printf("command not found:\n");
			ft_free_2dtab(cmd);
			exit(0);
		}
		free(cmd[0]);
		cmd[0] = path;
	}
	execve(cmd[0], &cmd[0], 0);
	ft_free_2dtab(cmd);
}
