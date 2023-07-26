/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/26 18:22:28 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	main(void)
{
	t_env	e;

	while (1)
	{
		e.readline = readline("Minishell❤️ :");
		printf("%s\n", e.readline);
		e.tokens = ft_split_to_tokens(e.readline);
		free(e.readline);
		if (!e.tokens)
			return (0);
		while ((*e.tokens))
			printf("%s\n", (*e.tokens++));
	}
	return (0);
}
