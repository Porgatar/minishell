/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:56:57 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/10/12 13:39:43 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env_clear(t_env **lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = *lst;
	}
}

void	ft_cmd_clear(t_cmd **lst)
{
	t_cmd	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		ft_free_2dtab((*lst)->cmd);
		*lst = (*lst)->next;
		free(tmp);
		tmp = *lst;
	}
}
