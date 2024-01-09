/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:30 by luhego            #+#    #+#             */
/*   Updated: 2024/01/09 15:45:14 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function check for error of the export arg syntax.
*/
int	ft_check_error(char	*str, t_env *env)
{
	int	i;

	if (str[0] == '=' || str[0] == '+')
		return (1);
	if (str[0] == '-')
		return (2);
	if ((str[0] >= '0' && str[0] <= '9'))
		return (1);
	i = 0;
	while (str[i] && str[i] != '+' && str[i] != '=')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] && str[i] == '+')
		return (1);
	if (!str[i])
	{
		ft_env_new(&env, str, &str[i]);
		return (IS_OK);
	}
	return (0);
}

/*
	this function delete a var in the t_env chained list.
*/
int	ft_unset(t_cmd *cmds, t_env *env)
{
	int		i;
	t_env	*ptr;

	if (cmds->prev || cmds->next)
		return (0);
	if (cmds->cmd[1] && cmds->cmd[1][0] == '-')
	{
		printf("invalid option\n");
		return (2);
	}
	i = -1;
	while (cmds->cmd[++i])
	{
		ptr = ft_get_env_value(cmds->cmd[i], env);
		if (ptr != 0)
		{
			while (env->next != ptr)
				env = env->next;
			env->next = env->next->next;
			free(ptr->key);
			free(ptr->value);
			free(ptr);
		}
	}
	return (0);
}
