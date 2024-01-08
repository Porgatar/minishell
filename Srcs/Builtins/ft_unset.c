/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:30 by luhego            #+#    #+#             */
/*   Updated: 2024/01/08 15:35:59 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_error(char	*str)
{
	int	i;

	if (str[0] == '=' || str[0] == '+')
		return (1);
	if (str[0] == '-')
		return (2);
	i = -1;
	while (str[++i] && str[i] != '+' && str[i] != '=')
		if ((str[i] >= '0' && str[i] <= '9'))
			return (1);
	if (str[i] == '+')
		i++;
	if ((str[i] && str[i] != '=') || (str[i] == '=' && \
	(str[i + 1] == '=' || str[i + 1] == '+')))
		return (1);
	if (!str[i] || (str[i] && !str[i + 1]))
		return (321);
	return (0);
}

int	ft_unset(t_cmd *cmds, t_env *env)
{
	int		i;
	t_env	*ptr;

	i = -1;
	if (cmds->prev || cmds->next)
		return (0);
	if (cmds->cmd[1][0] == '-')
	{
		printf("invalid option\n");
		return (2);
	}
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
