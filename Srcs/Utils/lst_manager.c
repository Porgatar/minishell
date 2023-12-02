/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:34:08 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 14:37:26 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function roll the list to go back at the top of it.
*/
void	ft_rollback_lst(t_cmd **cmds)
{
	while ((*cmds)->prev)
		*cmds = (*cmds)->prev;
}

/*
	this function swap 2 list of th t_env chained list.
*/
void	ft_lstswap(t_env *a, t_env *b)
{
	char	*tmp;

	tmp = a->key;
	a->key = b->key;
	b->key = tmp;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}
