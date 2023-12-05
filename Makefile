# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 15:28:55 by luhego & parinder #+#    #+#              #
#    Updated: 2023/12/05 16:33:35 by parinder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS=	--silent

NAME=		minishell

CC=			clang

CFLAGS=		-Wall -Werror -Wextra -g

OBJ=		$(SRCS:.c=.o)

SRCS=		Srcs/main.c \
			Srcs/ft_split_to_tokens.c \
			Srcs/ft_parse_to_cmds.c \
			Srcs/ft_expand_cmds.c \
			Srcs/ft_redirect.c \
			Srcs/ft_heredoc.c \
			Srcs/ft_exec_pipeline.c \
\
			Srcs/Builtins/ft_exec_builtins.c \
			Srcs/Builtins/ft_echo.c \
			Srcs/Builtins/ft_pwd.c \
			Srcs/Builtins/ft_export.c \
			Srcs/Builtins/ft_env.c \
			Srcs/Builtins/ft_exit.c \
			Srcs/Builtins/ft_cd.c \
\
			Srcs/Utils/ft_split.c \
			Srcs/Utils/ft_substr.c \
			Srcs/Utils/ft_strlcpy.c \
			Srcs/Utils/is_space.c \
			Srcs/Utils/ft_free_2dtab.c \
			Srcs/Utils/ft_lst_clear.c \
			Srcs/Utils/lst_manager.c \
			Srcs/Utils/ft_strncmp.c \
			Srcs/Utils/ft_strlen.c \
			Srcs/Utils/ft_strdup.c

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline
			echo $(On_IGreen)"                                 "$(Color_Off)
			echo $(On_IGreen)$(BGreen)"       project compiled!        "$(Color_Off)
			echo $(On_IGreen)"                                 "$(Color_Off)

clean:
			rm -f $(OBJ)
			echo $(On_IGreen)"                                 "$(Color_Off)
			echo $(On_IGreen)$(BYellow)"       objects cleaned!         "$(Color_Off)
			echo $(On_IGreen)"                                 "$(Color_Off)

fclean:		clean
			rm -f $(NAME)
			echo $(On_IGreen)"                                 "$(Color_Off)
			echo $(On_IGreen)$(BYellow)"    project fully cleaned!      "$(Color_Off)
			echo $(On_IGreen)"                                 "$(Color_Off)

re:			fclean all

.PHONY:		all clean fclean re

#	-	-	-	-	-	Colors	-	-	-	-	-	-	#
#														|
BGreen=		'\033[1;32m'		#Bold Green				|
BYellow=	'\033[1;33m'		#Bold Yellow			|
#														|
On_IGreen=	'\033[0;102m'		#H.I-Green Background	|
#														|
Color_Off=	'\033[0m'			#Color Reset			|
#														|
#	-	-	-	-	-	-	-	-	-	-	-	-	-	#
