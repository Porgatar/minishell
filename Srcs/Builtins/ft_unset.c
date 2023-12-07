/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:30 by luhego            #+#    #+#             */
/*   Updated: 2023/12/07 17:32:01 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_unset(t_cmd *cmds, t_env *env)
{
	t_env	*ptr;

	ptr = ft_get_env_value(cmds->cmd[1], env);
	if (ptr != 0)
	{
		while (env->next != ptr)
			env = env->next;
		env->next = env->next->next;
		free(ptr->key);
		free(ptr->value);
		free(ptr);
	}
	return (0);
}
