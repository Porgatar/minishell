/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:30 by luhego            #+#    #+#             */
/*   Updated: 2024/01/03 17:24:05 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' || str[i] <= '9')
			return (1);
		i++;
	}
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
