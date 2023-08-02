/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:56:57 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/02 11:14:35 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear(t_cmd **cmds)
{
	t_cmd	*tmp;

	if (!cmds)
		return ;
	tmp = *cmds;
	while (*cmds)
	{
		ft_free_2dtab(*cmds->cmd);
		*cmds = *cmds->next;
		free(tmp);
		tmp = *cmds;
	}
}
