/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:24 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/07/24 18:54:07 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	-	-	-	-	Includes	-	-	-	-	*/

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

/*	-	-	-	-	PrintColors	-	-	-	-	*/

# define RED	"\033[0;31m"
# define RESET	"\033[0m"

/*	-	-	-	-	Defines		-	-	-	-	*/

size_t	g_error;

/*	-	-	-	-	Typedefs	-	-	-	-	*/

typedef struct s_env
{
	char	*readline;
}	t_env;

/*	-	-	-	-	main.c		-	-	-	-	*/



#endif
