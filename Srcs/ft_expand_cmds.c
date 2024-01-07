/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:49:54 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/17 19:30:11 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function join to *expanded the non-special chars that are found in S
	if succed, return i readed char in the process.
*/
static int	ft_join(char **expanded, char *s, char sep)
{
	char	*new;
	char	*joined;
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == '$' || (sep && (s[i] == '\'' || s[i] == '"')))
			break ;
	new = ft_substr(s, 0, i);
	joined = ft_strjoin(*expanded, new);
	if (joined)
	{
		free(*expanded);
		free(new);
		*expanded = joined;
	}
	else
	{
		if (*expanded)
			free(*expanded);
		*expanded = new;
	}
	return (i);
}

/*
	this function expand all key that are to be found in S and
	return the new created string.
*/
char	*ft_expand_str(char *s, char sep, t_env *env)
{
	char	*expanded;
	int		i;
	char	quote;

	expanded = 0;
	i = 0;
	quote = 0;
	while (s[i])
	{
		if (sep && !quote && s[i] && (s[i] == '"' || s[i] == '\''))
			quote = s[i++];
		else if (s[i] && s[i] == '$' && (!sep || quote != sep))
			i += ft_expand_key(&expanded, &s[i], env);
		else if (sep && s[i] && s[i] == quote)
		{
			quote = 0;
			i++;
		}
		else
			i += ft_join(&expanded, &s[i], sep);
		if (i == -1)
			return (s);
	}
	free(s);
	return (expanded);
}

/*
	this function expand all key('$') that are to be found in the pipeline.
*/
void	ft_expand_cmds(t_cmd *cmds, t_env *env)
{
	int	i;

	while (cmds)
	{
		i = 0;
		while (cmds->cmd[i])
		{
			cmds->cmd[i] = ft_expand_str(cmds->cmd[i], '\'', env);
			if (cmds->cmd[i] && !ft_strncmp(cmds->cmd[i], "<<", 3))
				i++;
			i++;
		}
		cmds = cmds->next;
	}
}
