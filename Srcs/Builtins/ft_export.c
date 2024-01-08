/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:17:49 by parinder          #+#    #+#             */
/*   Updated: 2024/01/08 15:39:54 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function duplicate the t_env chained list and return it,
	return 0 if it failed to duplicate it.
*/
static t_env	*ft_dup_env(t_env *env)
{
	t_env	*first_var;
	t_env	*export;

	export = malloc(sizeof(t_env));
	first_var = export;
	while (env)
	{
		if (!export)
		{
			ft_env_clear(first_var);
			return (0);
		}
		export->key = ft_strdup(env->key);
		export->value = ft_strdup(env->value);
		env = env->next;
		if (env)
		{
			export->next = malloc(sizeof(t_env));
			export = export->next;
		}
	}
	export->next = 0;
	return (first_var);
}

/*
	this function dup the t_env chained list and sort it in alphabetik order.
*/
static t_env	*ft_sort_env(t_env *env)
{
	t_env	*first;
	t_env	*tmp;

	env = ft_dup_env(env);
	first = env;
	while (env)
	{
		tmp = env;
		while (tmp)
		{
			if (ft_strncmp(env->key, tmp->key, ft_strlen(env->key) + 1) > 0)
				ft_lstswap(env, tmp);
			tmp = tmp->next;
		}
		env = env->next;
	}
	return (first);
}

/*
	this function sort the t_env chained list and
	displays it like ft_env but in a different format.
*/
static void	ft_display_export(t_cmd *cmds, t_env *env)
{
	t_env	*tmp;

	env = ft_sort_env(env);
	tmp = env;
	while (env)
	{
		write(cmds->fd_out, "declare -x ", 11);
		write(cmds->fd_out, env->key, ft_strlen(env->key));
		write(cmds->fd_out, "=\"", 2);
		write(cmds->fd_out, env->value, ft_strlen(env->value));
		write(cmds->fd_out, "\"\n", 2);
		env = env->next;
	}
	ft_env_clear(tmp);
}

/*
	this function split S and export it in the t_env chained list
	in format key=value.
*/
static int	ft_export_env(char *s, t_env *env)
{
	int		i;
	int		error;
	t_env	*var;
	char	*tmp;

	error = ft_check_error(s);
	if (error)
		return (error);
	i = 0;
	while (s[i] && s[i] != '=' && s[i] != '+')
		i++;
	s[i] = 0;
	var = ft_get_env_value(s, env);
	if (s[i + 1] == '=' && var)
	{
		tmp = ft_strjoin(var->value, &s[i + 2]);
		free(var->value);
		var->value = tmp;
		return (0);
	}
	if (s[i + 1] == '=')
		ft_env_new(&env, s, &s[i + 2]);
	else
		ft_env_new(&env, s, &s[i + 1]);
	return (0);
}

/*
	ft_export displays the env chained list in alphabetik order if no args are sent,
	but set a new or already set variable to a new value for all args sent.
*/
int	ft_export(t_cmd *cmds, t_env *env)
{
	int	i;
	int	error;

	if (!cmds->cmd[1])
	{
		ft_display_export(cmds, env);
		return (0);
	}
	if (cmds->prev || cmds->next)
		return (0);
	i = 1;
	while (cmds->cmd[i])
	{
		error = ft_export_env(cmds->cmd[i], env);
		if (error && error != IS_OK)
		{
			printf("%sminishell: export: `%s' not a valid identifier%s\n", \
			RED, cmds->cmd[i], RESET);
			return (error);
		}
		i++;
	}
	return (0);
}
