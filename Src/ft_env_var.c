/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:23:09 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/10/24 00:01:13 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static void	ft_envcpy(const char *var, char **name, char **value)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	*name = ft_substr(var, 0, i);
	*value = ft_substr(var, i + 1, 2147483647);
}

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
}