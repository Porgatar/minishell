/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:51:12 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/31 21:31:11 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*ft_parse_to_cmds(const char **tokens)
{
	t_cmd	*cmds;
	int		i;

	cmds = malloc(sizeof(t_cmd));
	i = 0;
	while(tokens[i])
	{
		if (!cmds)
			
		i = ft_init_cmd(tokens[i]);
	}
	return ();
}
