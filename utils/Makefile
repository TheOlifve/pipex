# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 01:47:32 by hrahovha          #+#    #+#              #
#    Updated: 2023/03/19 17:32:27 by hrahovha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libutils.a

SRC =	get_next_line.c	\
		ft_itoa.c		\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlen.c		\
		ft_strrncmp.c	\
		ft_substr.c		\
		ft_printf.c		\
		ft_memset.c		\
		ft_strcmp.c		\
		ft_strncmp.c	\
		msg.c			

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
