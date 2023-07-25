/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:00 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/25 18:27:40 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_exec_cmd(char **cmd)
{
	int	i;

//	printf("executing \"%s\"", cmd[0]);
	i = 0;
	while (cmd[i])
		printf("arg %d = \"%s\"", cmd[i++]);
}
