/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/31 15:59:55 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**tokens;
	t_cmd	*cmds;
	int		i;

	(void)ac;
	(void)av;
	(void)envp;
	while (1)
	{
		line = readline("Minishell❤️ :");
		tokens = ft_split_to_tokens(line);
		free(line);
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
