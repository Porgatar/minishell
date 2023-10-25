/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/10/25 19:08:56 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_tab(char **tokens, t_env *env)
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
		ft_env_clear(env);
		exit(0);
	}
}

static void	print_list(t_cmd *cmds, char *s)
{
	t_cmd	*cmd;
	int		i;

	printf("%s\n%s\n%s", RED, s, RESET);
	cmd = cmds;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
		{
			if (cmd->cmd[i])
			{
				if (cmd->cmd[i][0] == '|')
					printf("\n");
				printf("%s, ", cmd->cmd[i]);
				if (cmd->cmd[i][0] == '|')
					printf("\n");
			}
			i++;
		}
		printf("\n");
		cmd = cmd->next;
	}
}

static void	print_env(t_env *cmds)
{
	t_env	*cmd;

	printf("%s\nenv:%s\n", RED, RESET);
	cmd = cmds;
	while (cmd)
	{
		printf("%s", cmd->key);
		printf("=%s", cmd->value);
		printf("\n");
		cmd = cmd->next;
	}
	printf("\n");
}

int	main(int ac, char **av, char **envp)
{
	char	**tokens;
	t_cmd	*cmds;
	t_env	*env;

	(void)ac;
	(void)av;
	env = ft_index_env(envp);
	print_env(env);
	while (1)
	{
		tokens = ft_split_to_tokens(readline("Minishell❤️ :"));
		if (tokens)
		{
			print_tab(tokens, env);
			cmds = ft_parse_to_cmds(tokens);
			free(tokens);
			if (cmds)
			{
				print_list(cmds, "**cmds(one pipe per line)");
				ft_expand_and_redirect(cmds, env);
				print_list(cmds, "**expanded_cmds(one pipe per line)");
				ft_cmd_clear(cmds);
			}
		}
	}
	ft_env_clear(env);
	return (0);
}
