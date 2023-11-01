# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 15:28:55 by luhego & parinder #+#    #+#              #
#    Updated: 2023/11/01 20:18:53 by parinder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS=	--silent

NAME=		minishell

CC=			gcc

CFLAGS=		-Wall -Werror -Wextra -g

OBJ=		$(SRCS:.c=.o)

SRCS=		Srcs/main.c \
			Srcs/ft_split_to_tokens.c \
			Srcs/ft_parse_to_cmds.c \
			Srcs/ft_expand_and_redirect.c \
			Srcs/ft_env_var.c \
			Srcs/Builtins/ft_pwd.c \
			Utils/ft_substr.c \
			Utils/ft_strlcpy.c \
			Utils/is_space.c \
			Utils/ft_free_2dtab.c \
			Utils/ft_lst_clear.c \
			Utils/ft_strncmp.c \
			Utils/ft_strlen.c

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
