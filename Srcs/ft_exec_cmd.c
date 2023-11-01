/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/14 23:48:22 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exec_cmd(char **cmd)
{
	int	i;

	i = 0;
	printf("Execute :\n");
	while (cmd[i])
		printf("%s, ", cmd[i++]);
	printf("\n");
}
