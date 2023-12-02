/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 13:16:12 by parinder         ###   ########.fr       */
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
	int		j;

	printf("%s\n%s\n%s", RED, s, RESET);
	cmd = cmds;
	j = 0;
	while (cmd)
	{
		printf("maillon num = %d\ntab (une chaine par virgule)= ", j);
		i = 0;
		while (cmd->cmd[i])
		{
			if (cmd->cmd[i])
				printf("%s, ", cmd->cmd[i]);
			i++;
		}
		printf("\n");
		if (!ft_strncmp(s, "**f", 3))
			printf("fd_in = %i, fd_out = %i\n\n", cmd->fd_in, cmd->fd_out);
		cmd = cmd->next;
		j++;
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

/*
	this programm is a feature less bash shell.
*/
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
				ft_expand_cmds(cmds, env);
				print_list(cmds, "**expanded_cmds(one pipe per line)");
				ft_redirect(cmds);
				print_list(cmds, "**ft_redirected_cmds(one pipe per line)");
				ft_exec_pipeline(cmds, env);
				waitpid(0, 0, 0);
				ft_cmd_clear(cmds);
			}
		}
	}
	ft_env_clear(env);
	return (0);
}
