/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:30 by luhego            #+#    #+#             */
/*   Updated: 2024/01/09 22:45:32 by parinder         ###   ########.fr       */
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
		if (!ft_get_env_value(str, env))
			ft_env_new(&env, str, &str[i]);
		return (IS_OK);
	}
	return (0);
}

/*
	this function delete one list of the t_env chained list.
*/
static void	ft_delone(char *s, t_env **env)
{
	t_env	*ptr;
	t_env	*tmp;

	tmp = *env;
	ptr = ft_get_env_value(s, *env);
	if (ptr)
	{
		if (ptr == tmp)
			*env = tmp->next;
		else if (tmp)
		{
			while (tmp->next != ptr)
				tmp = tmp->next;
			tmp->next = tmp->next->next;
		}
		free(ptr->key);
		free(ptr->value);
		free(ptr);
	}
}

/*
	this function delete a var in the t_env chained list.
*/
int	ft_unset(t_cmd *cmds, t_env **env)
{
	int		i;

	if (cmds->prev || cmds->next)
		return (0);
	if (cmds->cmd[1] && cmds->cmd[1][0] == '-')
	{
		printf("%sminishell: unset: -%c: invalid option%s\n", \
		RED, cmds->cmd[1][1], RESET);
		return (2);
	}
	i = 0;
	while (cmds->cmd[i])
	{
		ft_delone(cmds->cmd[i], env);
		i++;
	}
	return (0);
}
