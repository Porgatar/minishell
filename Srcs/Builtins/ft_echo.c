/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:12:42 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/17 17:05:33 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	this function check if there is the -n option in the given string and
	return 1 if thats the only option found, return 0 if not.
*/
int	ft_get_option(const char *str)
{
	int	i;
	int	is_n;

	if (!str)
		return (0);
	i = 0;
	is_n = 0;
	if (str[0] == '-')
		i++;
	else
		return (0);
	while (str[i])
	{
		if (str[i++] == 'n')
			is_n = 1;
		else
			return (0);
	}
	return (is_n);
}

/*
	this function print all of its argument seperated by a single ' ' space char.
	if the first arg is == "-n" then skip the newline char at the end.
*/
int	ft_echo(t_cmd *cmds)
{
	int	i;
	int	is_n;

	i = 1;
	while (ft_get_option(cmds->cmd[i]))
		i++;
	is_n = 0;
	if (i > 1)
		is_n = 1;
	while (cmds->cmd[i])
	{
		write(cmds->fd_out, cmds->cmd[i], ft_strlen(cmds->cmd[i]));
		i++;
		if (cmds->cmd[i])
			write(cmds->fd_out, " ", 1);
	}
	if (!is_n)
		write(cmds->fd_out, "\n", 1);
	return (0);
}
