# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parinder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 16:09:10 by parinder          #+#    #+#              #
#    Updated: 2023/01/25 14:30:55 by parinder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libft.a

CC=			clang

CFLAGS=		-Wall -Werror -Wextra

OBJ=		$(SRC:.c=.o)

BOBJ=		$(BSRC:.c=.o)

SRC=		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_atol.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_printf.c \
			ft_printf_initvar.c \
			ft_printf_putvar.c \
			ft_printf_putstr.c \
			ft_printf_putnbr.c \
			ft_printf_putwidth.c \
			get_next_line.c

BSRC=		ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

MAKEFLAGS=	--no-print-directory

ifdef BONUS
	SRC += $(BSRC)
endif

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

bonus:		$(OBJ) $(BOBJ)
			@make BONUS=true

clean:		
			rm -f $(OBJ) $(BOBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
