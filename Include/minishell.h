/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:24 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/26 21:53:06 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	-	-	-	-	Includes	-	-	-	-	*/

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

/*	-	-	-	-	PrintColors	-	-	-	-	*/

# define RED	"\033[0;31m"
# define RESET	"\033[0m"

/*	-	-	-	-	Defines		-	-	-	-	*/


/*	-	-	-	-	Typedefs	-	-	-	-	*/

/*
typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}	t_cmd;
*/

typedef struct s_env
{
	char	*readline;
	char	**tokens;
}	t_env;

/*	-	-	-	-	main.c		-	-	-	-	*/

/*	-	-	ft_split_to_tokens.c		-	-	*/

char	**ft_split_to_tokens(const char *str);

/*	-	-	-	-	main.c		-	-	-	-	*/
void	ft_free_2dtab(char **str, int i);
int		is_space(char c);

#endif
