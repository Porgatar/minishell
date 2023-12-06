/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:23:09 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/07 00:11:23 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this fuction go though the t_env chained list to find key and
	return a pointer to the found list.
	return 0 if the list with the right key has been not found.
*/
t_env	*ft_get_env_value(const char *key, t_env *env)
{
	while (env)
	{
		if (env->key && !ft_strncmp(env->key, key, ft_strlen(env->key) + 1))
			break ;
		env = env->next;
	}
	return (env);
}

/*
	
*/
static int	is_env(t_env *env, const char *key, const char *value)
{
	t_env	*var;

	var = ft_get_env_value(key, env);
	if (!var)
		return (0);
	free(var->value);
	var->value = ft_strdup(value);
	return (1);
}

/*
	this function add a new list to the env chained list.
*/
int	ft_env_new(t_env **env, const char *key, const char *value)
{
	t_env	*lst;
	t_env	*new;

	if (is_env(*env, key, value))
		return (0);
	new = malloc(sizeof(t_env));
	if (!new)
		return (-1);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = 0;
	if (!*env)
	{
		*env = new;
		return (0);
	}
	lst = *env;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	return (0);
}

/*
	ft_index_env go though all the **envp tab to copie it to
	a chained list of key=value args with the help of the ft_envcpy and
	return a pointer to the top of the list.
*/
t_env	*ft_index_env(char **envp)
{
	t_env	*env;
	int		i;
	int		j;

	env = 0;
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		envp[i][j] = 0;
		ft_env_new(&env, envp[i], &envp[i][j + 1]);
		i++;
	}
	return (env);
}

/*
	this function go though the t_env chained list and print all its data
	in the format "key=value'\n'".
*/
int	ft_env(t_cmd *cmds, t_env *env)
{
	if (cmds->cmd[1])
	{
		perror(cmds->cmd[1]);
		return (127);
	}
	while (env)
	{
		write(cmds->fd_out, env->key, ft_strlen(env->key));
		write(cmds->fd_out, "=", 1);
		write(cmds->fd_out, env->value, ft_strlen(env->value));
		write(cmds->fd_out, "\n", 1);
		env = env->next;
	}
	return (0);
}
