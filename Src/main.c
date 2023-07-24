/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/24 19:06:22 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	main(void)
{
	t_env	e;

	while (1)
	{
		e.readline = readline("Minishell❤️ :");
		printf("\"%s\"\n", e.readline);
		free(e.readline);
	}
	return (0);
}
