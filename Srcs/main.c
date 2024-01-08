/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2024/01/08 16:49:10 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_status;

/*
	this function display the prompt and wait for readline to execute it.
*/
static void	ft_promptloop(char *line, t_env *env)
{
	char	**tokens;
	t_cmd	*cmds;

	tokens = ft_split_to_tokens(line);
	if (!ft_check_syntax(tokens))
	{
		cmds = ft_parse_to_cmds(tokens);
		if (cmds)
		{
			ft_expand_cmds(cmds, env);
			g_status = 0;
			if (!ft_heredoc(cmds, env))
			{
				ft_redirect(cmds);
				ft_exec_pipeline(cmds, env);
			}
			ft_cmd_clear(cmds);
		}
	}
	else if (tokens)
		ft_free_2dtab(tokens);
	else
		ft_exit(0, env);
}

/*
	this programm is a feature less bash shell.
*/
int	main(int ac, char **av, char **envp)
{
	t_env	*env;
	char	*line;

	(void)ac;
	(void)av;
	g_status = 0;
	env = ft_index_env(envp);
	ft_set_sighandler(PROMPT);
	while (1)
	{
		line = readline("Minishell❤️ :");
		if (line && line[0])
			add_history(line);
		ft_promptloop(line, env);
	}
	return (0);
}
