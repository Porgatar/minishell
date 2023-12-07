/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:49:54 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/07 16:10:59 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function join to *expanded the non-special chars that are found in S
	if succed, return i readed char in the process.
*/
static int	ft_join(char **expanded, char *s, char quote, char sep)
{
	char	*new;
	char	*joined;
	int		i;

	i = -1;
	while (s[++i] && s[i] != quote)
		if (s[i] == '$' && (!sep || quote != sep))
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
	this function expand the found key and join it to *expanded if
	succed, return i readed char in the process.
*/
static int	ft_is_key(char **expanded, char *s, t_env *env)
{
	t_env	*var;
	char	*key;
	int		i;

	i = 0;
	while (s[i] && !is_space(s[i]) && s[i] != '\'' && s[i] != '"')
		i++;
	if (s[i])
		key = ft_substr(s, 1, i - 1);
	else
		key = ft_substr(s, 1, i);
	var = ft_get_env_value(key, env);
	free(key);
	if (var)
	{
		if (*expanded)
		{
			key = ft_strjoin(*expanded, var->value);
			free(*expanded);
			*expanded = key;
		}
		else
			*expanded = ft_strdup(var->value);
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
			i += ft_is_key(&expanded, &s[i], env);
		else if (sep && s[i] && s[i] == quote)
		{
			quote = 0;
			i++;
		}
		else
			i += ft_join(&expanded, &s[i], quote, sep);
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
			if (!ft_strncmp(cmds->cmd[i], "<<", 3))
				i++;
			i++;
		}
		cmds = cmds->next;
	}
}
