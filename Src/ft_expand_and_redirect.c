/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_and_redirect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:49:54 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/15 23:10:51 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_var_len(const char *s)
{
	char	*var;
	char	*to_find;
	int		i;

	i = 0;
	while (s[i] && !is_space(s[i]))
		i++;
	to_find = ft_substr(s, 0, i);
	var = ft_get_var
	return (i);
}

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
		if (s[i] == '$' && quote != '\'')
		{
			count += ft_var_len(&s[i], env);
			while (s[i] && !is_space(s[i]) && s[i] != quote)
				i++;
		}
		if (s[i] && s[i] == quote)
			quote = 0;
		else
			count++;
		i++;
	}
	return (count);
}

static char	*ft_expand_str(char *s, t_env *env)
{
//	char	*new_s;
//	char	*var;
	int		expanded_len;
//	int		quote;
//	int		i;

	expanded_len = ft_expanded_str_len(s, env);
	printf("len = %d\n", expanded_len);
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
