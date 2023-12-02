/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:06:29 by parinder          #+#    #+#             */
/*   Updated: 2023/12/02 18:03:34 by parinder         ###   ########.fr       */
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
	getcwd(path, 1024);
	write(cmd->fd_out, path, ft_strlen(path) + 1);
	write(cmd->fd_out, "\n", 2);
	return (0);
}
