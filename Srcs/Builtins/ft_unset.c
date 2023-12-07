/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:30 by luhego            #+#    #+#             */
/*   Updated: 2023/12/07 20:11:47 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_unset(t_cmd *cmds, t_env *env)
{
	int		i;
	t_env	*ptr;

	i = 0;
	while (cmds->cmd[i])
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
		i++;
	}
	return (0);
}
