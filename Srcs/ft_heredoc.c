/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:47:33 by parinder          #+#    #+#             */
/*   Updated: 2023/12/12 22:23:07 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function unquote the word and return a pointer to the new string
	created without quote.
*/
static char	*ft_unquote(char *word)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (word[++i])
		if (word[i] != '\'' && word[i] != '"')
			len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (word);
	i = -1;
	len = 0;
	while (word[++i])
	{
		if (word[i] != '\'' && word[i] != '"')
		{
			str[len] = word[i];
			len++;
		}
	}
	str[len] = 0;
	free(word);
	return (str);
}

/*
	this function loop read the terminal with readline and
	write the expanded lines in the pipe till word(cmds->cmd[i + 1])
	is read or '\n' if word is empty.
	return line if EOF is found.
*/
static int	ft_read(t_cmd *cmds, int i, int *fd, t_env *env)
{
	char		*str;
	static int	line = 1;

	while (1)
	{
		str = readline("> ");
		if (!str)
			return (line);
		if (!ft_strncmp(str, cmds->cmd[i + 1], ft_strlen(str) + 1))
		{
			free(str);
			return (0);
		}
		str = ft_expand_str(str, 0, env);
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
		free(str);
		if (!cmds->cmd[i + 1][0])
			return (0);
		line++;
	}
	return (0);
}

/*
	this function create a pipe that hear out the terminal to fill it and
	return a O_RDONLY fd to it.
*/
static int	ft_set_heredoc(t_cmd *cmds, int i, t_env *env)
{
	int		fd[2];
	int		tmp;
	int		line;

	pipe(fd);
	tmp = dup(0);
	cmds->cmd[i + 1] = ft_unquote(cmds->cmd[i + 1]);
	ft_set_sighandler(HEREDOC);
	line = ft_read(cmds, i, fd, env);
	if (line && g_status != 130)
	{
		printf("\n%sminishell: warning: here-document at line ", RED);
		printf("%d delimited by end-of-file ", line);
		printf("(wanted `%s')%s\n", cmds->cmd[i + 1], RESET);
	}
	close(fd[1]);
	dup2(tmp, 0);
	close(tmp);
	ft_set_sighandler(FORK);
	if (g_status)
	{
		close(fd[0]);
		return (-101);
	}
	return (fd[0]);
}

/*

*/
void	ft_heredoc(t_cmd *cmds, t_env *env)
{
	int	i;

	while (cmds)
	{
		i = 0;
		cmds->heredoc = -1;
		if (cmds->prev && cmds->prev->heredoc == -101)
			cmds->heredoc = -101;
		while (cmds->heredoc != -101 && cmds->cmd[i])
		{
			if (ft_strncmp(cmds->cmd[i], "<<", 0))
			{
				if (cmds->heredoc >= 0)
					close(cmds->heredoc);
				cmds->heredoc = ft_set_heredoc(cmds, i, env);
				if (cmds->heredoc == -101)
					break ;
			}
			else
				i++;
		}
		if (!cmds->next)
			break ;
		cmds = cmds->next;
	}
}
