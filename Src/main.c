/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/28 15:07:49 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	main(void)
{
	t_env	e;
	int		i;

	while (1)
	{
		e.readline = readline("Minishell❤️ :");
		e.tokens = ft_split_to_tokens(e.readline);
		free(e.readline);
		if (e.tokens)
		{
			i = 0;
			while ((e.tokens[i]))
				printf("%s\n", (e.tokens[i++]));
			if(e.tokens[0][0] == 'e' && e.tokens[0][1] == 'x' \
			&& e.tokens[0][2] == 'i' && e.tokens[0][3] == 't')
			{
				ft_free_2dtab(e.tokens, i);
				exit(0);
			}
			ft_free_2dtab(e.tokens, i);
		}
	}
	return (0);
}
