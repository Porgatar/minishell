/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_and_redirect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:49:54 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/10/12 14:00:18 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_expand	*ft_get_expand(const char *s, int quote, t_env *env)
{
	t_expand	*expand;
	char		*key;
	int			i;

	expand = malloc(sizeof(t_expand));
	i = 0;
	while (s[i] && !is_space(s[i]) && s[i] != quote)
		i++;
	key = ft_substr(s, 0, i);
	expand->env = ft_get_env_value(env, key);
	return (expand);
}

static t_expand	*ft_get_to_expand(const char *s, t_env *env)
{
	t_expand	*expanded;
	t_expand	*first;
	int			i;
	int			quote;

	first = 0;
	i = 0;
	quote = 0;
	while (s[i])
	{
		if (!quote && s[i] && (s[i] == '"' || s[i] == '\''))
			quote = s[i];
		else if (s[i] && s[i] != '$' && quote != '\'')
		{
			if (!first)
			{
				expanded = ft_get_expand(&s[i], quote, env);
				first = expanded;
			}
			else
			{
				expanded->next = ft_get_expand(&s[i], quote, env);
				expanded = expanded->next;
			}
		}
		else if (s[i] && s[i] == quote)
			quote = 0;
		i++;
	}
	return (first);
}
/*
static int	ft_expanded_str_len(char *s, t_env *env)
{
	int	i;
	int	count;
	int	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (s[i])
	{
		if (!quote && s[i] && (s[i] == '"' || s[i] == '\''))
			quote = s[i++];
		if (s[i] && s[i] == '$' && quote != '\'')
			while (s[i] && !is_space(s[i]) && s[i] != quote)
				i++;
		if (s[i] && s[i] == quote)
		{
			quote = 0;
			i++;
		}
		if (!s[i])
			break ;
		count++;
		i++;
	}
	return (count);
}
*/
static char	*ft_expand_str(char *s, t_env *env)
{
//	char	*new_s;
//	char	*var;
//	int		expanded_len;
	t_expand	*to_expand;
//	int		quote;
//	int		i;

	to_expand = ft_get_to_expand(s, env);
	while (to_expand)
	{
		if (to_expand->env)
			printf("key = %s, value = %s\n", to_expand->env->key, to_expand->env->value);
		to_expand = to_expand->next;
	}
//	expanded_len = ft_expanded_str_len(s, env);
//	printf("len = %d\n", expanded_len);
/*	if (expand_len == ft_strlen(s))
		return (s);
	new_s = malloc(sizeof(char) * (expand_len + 1));
	i = 0;
	while ()
	{
		.
		i++;
	}
	return (new_s);*/
	return (s);
}

void	ft_expand_and_redirect(t_cmd *cmds, int redirection[2], t_env *env)
{
	int	i;

	while (cmds)
	{
		i = 0;
		while (cmds->cmd[i])
		{
			cmds->cmd[i] = ft_expand_str(cmds->cmd[i], env);
			i++;
		}
		cmds = cmds->next;
	}
	ft_env_clear(&env);
	(void)redirection;
}
