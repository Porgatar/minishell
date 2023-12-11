/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:24 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/10 21:09:28 by parinder         ###   ########.fr       */
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
# include <signal.h>
# include <errno.h>

extern int	g_status;

/*	-	-	-	PrintColors	-	-	-	-	-	*/

# define RED	"\033[0;31m"
# define RESET	"\033[0m"

/*	-	-	-	Defines	-	-	-	-	-	-	*/

# define PROMPT		1
# define FORK		2
# define HEREDOC	3

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

/*	-	-	-	main.c	-	-	-	-	-	-	*/

void	ft_promptloop(t_env *env);

/*	-	-	-	ft_check_syntax.c	-	-	*/

int		ft_check_syntax(char **tokens);

/*	-	-	-	ft_split_to_tokens.c	-	-	*/

char	**ft_split_to_tokens(char *s);

/*	-	-	-	ft_parse_to_cmds.c	-	-	-	*/

t_cmd	*ft_parse_to_cmds(char **tokens);

/*	-	-	-	ft_expand_cmds.c	-	-	-	*/

char	*ft_expand_str(char *s, char sep, t_env *env);
void	ft_expand_cmds(t_cmd *cmds, t_env *env);

/*	-	-	-	ft_redirect.c	-	-	-	-	*/

void	ft_redirect(t_cmd *cmds, t_env *env);
void	ft_close_fds(t_cmd *cmds);

/*	-	-	-	ft_heredoc.c	-	-	-	-	*/

int		ft_heredoc(t_cmd *cmds, int i, t_env *env);

/*	-	-	-	ft_exec_pipeline.c	-	-	-	*/

void	ft_exec_pipeline(t_cmd *cmds, t_env *env);

/*	-	-	-	signals.c	-	-	-	-	-	*/

void	ft_set_sighandler(int mode);

/*	-	-	-	builtins dir	-	-	-	-	*/

//	-	ft_cd.c
int		ft_cd(t_cmd *cmds, t_env *env);

//	-	ft_echo.c
int		ft_echo(t_cmd *cmds);

//	-	ft_env.c
t_env	*ft_get_env_value(const char *key, t_env *env);
int		ft_is_env(t_env *env, const char *key, const char *value);
int		ft_env_new(t_env **env, const char *key, const char *value);
t_env	*ft_index_env(char **envp);
int		ft_env(t_cmd *cmds, t_env *env);

//	-	ft_exec_builtins.c
int		ft_exec_builtins(t_cmd *cmds, t_env *env);

//	-	ft_unset.c
int		ft_unset(t_cmd *cmds, t_env *env);

//	-	ft_exit.c
void	ft_exitshell(const char *error);
int		ft_exit(t_cmd *cmds, t_env *env);

//	-	ft_export.c
int		ft_export(t_cmd *cmds, t_env *env);

//	-	ft_pwd.c
int		ft_pwd(t_cmd *cmds);

/*	-	-	-	utils dir	-	-	-	-	-	*/

char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_free_2dtab(char **str);
int		is_space(char c);
void	ft_env_clear(t_env *lst);
void	ft_cmd_clear(t_cmd *lst);
void	ft_rollback_lst(t_cmd **cmds);
void	ft_lstswap(t_env *a, t_env *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);

#endif
