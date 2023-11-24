/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:24 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/11/24 19:16:35 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	-	-	-	Includes	-	-	-	-	-	*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

/*	-	-	-	PrintColors	-	-	-	-	-	*/

# define RED	"\033[0;31m"
# define RESET	"\033[0m"

/*	-	-	-	Defines	-	-	-	-	-	-	*/


/*	-	-	-	Typedefs	-	-	-	-	-	*/

typedef struct s_cmd
{
	char			**cmd;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_expand
{
	t_env			*env;
	struct s_expand	*next;
}	t_expand;

/*	-	-	-	main.c	-	-	-	-	-	-	*/

/*	-	-	-	ft_split_to_tokens.c	-	-	*/

char	**ft_split_to_tokens(char *s);

/*	-	-	-	ft_parse_to_cmds.c	-	-	-	*/

t_cmd	*ft_parse_to_cmds(char **tokens);

/*	-	-	-	ft_expand_cmds.c	-	-	-	*/

void	ft_expand_cmds(t_cmd *cmds, t_env *env);

/*	-	-	-	ft_exec_cmd.c	-	-	-	-	*/

void	ft_exec_cmd(char **cmd, t_env *env);

/*	-	-	-	builtins dir	-	-	-	-	*/

//	-	ft_exec_builtins.c
//int	ft_exec_builtins(t_cmd *cmds);

//	-	ft_env.c
t_env	*ft_get_env_value(const char *key, t_env *env);
t_env	*ft_index_env(char **envp);
//void	ft_env(t_cmd *cmds);

//	-	ft_pwd.c
void	ft_pwd(t_cmd *cmds);

/*	-	-	-	utils dir	-	-	-	-	-	*/

char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_free_2dtab(char **str);
int		is_space(char c);
void	ft_env_clear(t_env *lst);
void	ft_cmd_clear(t_cmd *lst);
void	ft_rollback_lst(t_cmd **cmds);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
