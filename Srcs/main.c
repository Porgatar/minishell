/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:30:58 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/17 18:32:37 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
static void	print_tab(char **tokens)
{
	int		i;

	printf("%s**tokens:\n%s", RED, RESET);
	i = 0;
	while ((tokens[i]))
		printf("%s\n", (tokens[i++]));
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
*/

int	g_status;

/*
	this function expand all key('$') that are to be found in the pipeline.
*/
static void	ft_expand_cmds(t_cmd *cmds, t_env *env)
{
	int	i;

	while (cmds)
	{
		i = 0;
		while (cmds->cmd[i])
		{
			cmds->cmd[i] = ft_expand_str(cmds->cmd[i], '\'', env);
			if (!ft_strncmp(cmds->cmd[i], "<<", 3))
				i++;
			i++;
		}
		cmds = cmds->next;
	}
}

/*
	this function display the prompt and wait for readline to execute it.
*/
void	ft_promptloop(t_env *env)
{
	char	*line;
	char	**tokens;
	t_cmd	*cmds;

	line = readline("Minishell❤️ :");
	if (line && line[0])
		add_history(line);
	tokens = ft_split_to_tokens(line);
	if (ft_check_syntax(tokens))
	{
//		print_tab(tokens);
		cmds = ft_parse_to_cmds(tokens);
		if (cmds)
		{
//			print_list(cmds, "**cmds(one pipe per line)");
			ft_expand_cmds(cmds, env);
//			print_list(cmds, "**expanded_cmds(one pipe per line)");
			g_status = 0;
			ft_redirect(cmds, env);
//			print_list(cmds, "**ft_redirected_cmds(one pipe per line)");
			ft_exec_pipeline(cmds, env);
			ft_cmd_clear(cmds);
		}
	}
	else if (tokens)
		free(tokens);
	else
		ft_exit(0, env);
}

/*
	this programm is a feature less bash shell.
*/
int	main(int ac, char **av, char **envp)
{
	t_env				*env;

	(void)ac;
	(void)av;
	g_status = 0;
	env = ft_index_env(envp);
//	print_env(env);
	ft_set_sighandler(PROMPT);
	while (1)
		ft_promptloop(env);
	return (0);
}
