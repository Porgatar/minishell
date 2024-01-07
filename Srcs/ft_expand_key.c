
#include "../minishell.h"

/*
	this function join the status to *expanded.
*/
static void	ft_get_status(char **expanded)
{
	char	*status;
	char	*joined;

	status = ft_itoa(g_status);
	if (*expanded)
	{
		joined = ft_strjoin(*expanded, status);
		free(*expanded);
		free(status);
		*expanded = joined;
	}
	else
		*expanded = status;
}

/*
	this function expand the errno global var and
	return 1 if status('?') has been found.
	return 0 if not.
*/
static int	ft_is_status(char **expanded, char *s)
{
	char	*status;
	char	*joined;
	int		i;

	i = 2;
	if (s[1] && s[1] == '?')
	{
		ft_get_status(expanded);
		while (s[i] && !is_space(s[i]) && s[i] != '$' && s[i] != '\'' && s[i] != '"')
			i++;
		status = ft_substr(s, 2, i - 2);
		joined = ft_strjoin(*expanded, status);
		free(*expanded);
		free(status);
		*expanded = joined;
		return (1);
	}
	return (0);
}

/*
	this function get the needed key in the t_env chained list and
	return its string value.
*/
static char	*ft_get_value(const char *s, int *j, t_env *env)
{
	t_env	*var;
	char	*key;
	int		i;

	i = 1;
	while (s[i] && !is_space(s[i]) && s[i] != '$' && s[i] != '\'' && s[i] != '"')
		i++;
	if (s[i])
		key = ft_substr(s, 1, i - 1);
	else
		key = ft_substr(s, 1, i);
	var = ft_get_env_value(key, env);
	free(key);
	*j = i;
	if (var)
		return (ft_strdup(var->value));
	return (ft_strdup(""));
}

/*
	this function expand the found key and join it to *expanded if
	succed, return i readed char in the process.
*/
int	ft_expand_key(char **expanded, char *s, t_env *env)
{
	char	*key;
	char	*value;
	int		i;

	value = ft_get_value(s, &i, env);
	if (!ft_is_status(expanded, s) && value)
	{
		if (*expanded)
		{
			key = ft_strjoin(*expanded, value);
			free(*expanded);
			*expanded = key;
		}
		else
			*expanded = ft_strdup(value);
	}
	if (value)
		free(value);
	return (i);
}
