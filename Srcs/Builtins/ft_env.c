/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:23:09 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/01 16:04:24 by parinder         ###   ########.fr       */
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
	split var using the = operator and copy it to
	key and value pointed strings respectively.
*/
void	ft_envcpy(const char *var, char **key, char **value)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	*key = ft_substr(var, 0, i);
	*value = ft_substr(var, i + 1, 2147483647);
}

/*
	ft_index_env go though all the **envp tab to copie it to
	a chained list of key=value args with the help of the ft_envcpy and
	return a pointer to the top of the list.
*/
t_env	*ft_index_env(char **envp)
{
	t_env	*first_var;
	t_env	*env;
	int		i;

	env = malloc(sizeof(t_env));
	first_var = env;
	i = 0;
	while (envp[i])
	{
		if (!env)
		{
			ft_env_clear(first_var);
			return (0);
		}
		ft_envcpy(envp[i], &env->key, &env->value);
		i++;
		if (envp[i])
		{
			env->next = malloc(sizeof(t_env));
			env = env->next;
		}
	}
	env->next = 0;
	return (first_var);
	return  (0);
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
