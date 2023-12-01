/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:17:49 by parinder          #+#    #+#             */
/*   Updated: 2023/12/01 19:06:30 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_env	*ft_dup_env(t_env *env)
{
	t_env	*first_var;
	t_env	*export;

	first_var = 0;
	while (env)
	{
		export = malloc(sizeof(t_env));
		if (!first_var)
			first_var = export;
		if (!export)
		{
			ft_env_clear(first_var);
			return (0);
		}
		export->key = ft_strdup(env->key);
		export->value = ft_strdup(env->value);
		env = env->next;
	}
	env->next = 0;
	return (first_var);
}

/*
static void	ft_sort_env(t_env *env)
{
	t_env	*dup;
	t_env	*tmp;

	dup = ft_dup_env(env);
	while (dup)
	{
		tmp = dup;
		while (tmp)
		{
			if (ft_strncmp(dup->key, tmp->key) > 0)
				ft_swap();
		}
		dup = dup->next;
	}
}
*/

static int	ft_display_export(t_cmd *cmds, t_env *env)
{
	env = ft_dup_env(env);
//	env = ft_sort_env(env);
	while (env)
	{
		write(cmds->fd_out, "declare -x ", 1);
		write(cmds->fd_out, env->key, ft_strlen(env->key));
		write(cmds->fd_out, "=\"", 2);
		write(cmds->fd_out, env->value, ft_strlen(env->value));
		write(cmds->fd_out, "\"\n", 2);
		env = env->next;
	}
	return (0);
}

/*
	ft_export displays the env chained list in alphabetik order if no args are sent,
	but set a new or already set variable to a new value for all args sent.
*/
int	ft_export(t_cmd *cmds, t_env *env)
{
	int	i;

	if (!cmds->cmd[1])
	{
		ft_display_export(cmds, env);
		return (0);
	}
	i = 0;
	while (cmds->cmd[i])
	{
		
		i++;
	}
	return (0);
}
