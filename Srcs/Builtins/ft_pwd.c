/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:06:29 by parinder          #+#    #+#             */
/*   Updated: 2024/01/09 16:41:27 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function print the path to working directory in fd_out.
*/
int	ft_pwd(t_cmd *cmd)
{
	char	path[1024];

	(void)cmd;
	if (!getcwd(path, 1024))
		return (0);
	write(cmd->fd_out, path, ft_strlen(path) + 1);
	write(cmd->fd_out, "\n", 2);
	return (0);
}
