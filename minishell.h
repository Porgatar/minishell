/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:24 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/08/15 20:00:22 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	-	-	-	Includes	-	-	-	-	-	*/

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

/*	-	-	-	PrintColors	-	-	-	-	-	*/

# define RED	"\033[0;31m"
# define RESET	"\033[0m"

/*	-	-	-	Defines	-	-	-	-	-	-	*/

/*	-	-	-	Typedefs	-	-	-	-	-	*/

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/*	-	-	-	main.c	-	-	-	-	-	-	*/

/*	-	-	-	ft_split_to_tokens.c	-	-	*/

char	**ft_split_to_tokens(char *s);

/*	-	-	-	ft_parse_to_cmds.c	-	-	-	*/

t_cmd	*ft_parse_to_cmds(char **tokens);

/*	-	-	-	ft_expand_and_redirect.c	-	*/

void	ft_expand_and_redirect(t_cmd *cmds, int redirection[2], t_env *env);

/*	-	-	-	ft_env_var.c	-	-	-	-	*/

char	*ft_get_env_var(t_env *env, const char *to_find);
t_env	*ft_index_env(char **envp);

/*	-	-	-	utils dir	-	-	-	-	-	*/
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_free_2dtab(char **str);
int		is_space(char c);
void	ft_env_clear(t_env **lst);
void	ft_cmd_clear(t_cmd **lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
