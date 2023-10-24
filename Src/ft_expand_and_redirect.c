/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_and_redirect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:49:54 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/10/24 17:11:35 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_expand	*ft_get_expand(const char *s, t_env *env)
{
	t_expand	*expand;
	char		*key;
	int			i;

	expand = malloc(sizeof(t_expand));
	i = 0;
	while (s[i] && !is_space(s[i]) && s[i] != '\'' && s[i] != '"')
		i++;
	if (s[i] == '"' || s[i] == '\'')
		i--;
	key = ft_substr(s, 1, i);
	printf("key = %s\n", key);
	expand->env = ft_get_env_value(key, env);
	free(key);
	return (expand);
}

static t_expand	*ft_get_to_expand(const char *s, int *len, t_env *env)
{
	t_expand	*expanded;
	t_expand	*first;
	int			i;
	int			quote;

	first = 0;
	i = 0;
	*len = 0;
	quote = 0;
	while (s[i])
	{
		if (!quote && s[i] && (s[i] == '"' || s[i] == '\''))
		{
			quote = s[i];
			*len -= 1;
		}
		else if (s[i] && s[i] == '$' && quote != '\'')
		{
			if (!first)
			{
				expanded = ft_get_expand(&s[i], env);
				*len += ft_strlen(expanded->env->value) - 1;
				first = expanded;
			}
			else
			{
				expanded->next = ft_get_expand(&s[i], env);
				*len += ft_strlen(expanded->env->value) - 1;
				expanded = expanded->next;
			}
			while (s[i] && !is_space(s[i]) && s[i] != quote)
				i++;
			i--;
		}
		else if (s[i] && s[i] == quote)
		{
			quote = 0;
			*len -= 1;
		}
		*len += 1;
		i++;
	}
	if (first)
		expanded->next = 0;
	return (first);
}

static char	*ft_expand_str(char *to_expand, t_expand *expand, int len)
{
	char	*expanded;
	int		i;
	int		copied;

	expanded = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (to_expand[i])
	{
		if (!quote && s[i] && (s[i] == '"' || s[i] == '\''))
			quote = s[i++];
		else if (s[i] && s[i] == '$' && quote != '\'')
		{
			while ()
				i++;
		}
	}
	return (expanded);
}

void	ft_expand_and_redirect(t_cmd *cmds, t_env *env)
{
	int			i;
	int			len;
	t_expand	*to_expand;

	while (cmds)
	{
		i = 0;
		while (cmds->cmd[i])
		{
			to_expand = ft_get_to_expand(cmds->cmd[i], &len, env);
			ft_expand_str(cmds->cmd[i], to_expand);
//			cmds->cmd[i] = ft_expand_str(cmds->cmd[i], env);
			i++;
		}
		cmds = cmds->next;
	}
}
