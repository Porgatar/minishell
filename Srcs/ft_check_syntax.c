/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:08:17 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/09 22:23:58 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_syntax(char **tokens)
{/*
	int	i;
	int	is_cmd;

	i = 0;
	is_cmd = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '<' || tokens[i][0] == '>')
			if (!tokens[++i] || tokens[i][0] == '<' || tokens[i][0] == '>' || tokens[i][0] == '|')
				return (0);
		i++;
	}*/
	if (!tokens || (tokens && !tokens[0]))
		return (0);
	return (1);
}
