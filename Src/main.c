/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/01 16:03:25 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_list(t_cmd *cmds)
{
	t_cmd	*cmd;
	int		i;

	cmd = cmds;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
			printf("%s, ", cmd->cmd[i]);
		printf("\n");
		cmd = cmd->next;
	}
}

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
		if (tokens)
		{
			i = 0;
			while ((tokens[i]))
				printf("%s\n", (tokens[i++]));
			if (tokens[0][0] == 'e' && tokens[0][1] == 'x' \
			&& tokens[0][2] == 'i' && tokens[0][3] == 't')
			{
				ft_free_2dtab(tokens, i);
				exit(0);
			}
			ft_free_2dtab(tokens, i);
		}
		cmds = ft_parse_to_cmds(tokens);
		if (cmds)
			print_list(cmds);
	}
	return (0);
}
