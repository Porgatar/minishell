/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/04 15:48:18 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_tab(char **tokens)
{
	int		i;

	printf("%s**tokens:\n%s", RED, RESET);
	i = 0;
	while ((tokens[i]))
		printf("%s\n", (tokens[i++]));
	if (tokens[0][0] == 'e' && tokens[0][1] == 'x' \
	&& tokens[0][2] == 'i' && tokens[0][3] == 't')
	{
		ft_free_2dtab(tokens);
		exit(0);
	}
}

static void	print_list(t_cmd *cmds)
{
	t_cmd	*cmd;
	int		i;

	printf("%s\n**cmds:\n%s", RED, RESET);
	cmd = cmds;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
		{
			if (cmd->cmd[i])
				printf("%s, ", cmd->cmd[i]);
			i++;
		}
		printf("\n");
		cmd = cmd->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	char	**tokens;
	t_cmd	*cmds;
	int		redirection[2];

	(void)ac;
	(void)av;
	(void)envp;
	while (1)
	{
		tokens = ft_split_to_tokens(readline("Minishell❤️ :"));
		if (tokens)
		{
			print_tab(tokens);
			cmds = ft_parse_to_cmds(tokens);
			free(tokens);
			if (cmds)
			{
				print_list(cmds);
				ft_expand_var(cmds, redirection);
				ft_lst_clear(&cmds);
			}
		}
	}
	return (0);
}
