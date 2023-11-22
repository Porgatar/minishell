/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:34:08 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/11/22 20:41:40 by parinder         ###   ########.fr       */
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
