NAME	=	pipex

CC		=	cc

RM		=	rm -rf

INCLUDE	=	pipex.h Makefile

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

IFLAGS	=	-I./utils

LFLAGS	=	-L./utils -lutils

SRC_DIR	=	./src/

OBJ_DIR	=	./obj/

SRC		=	$(wildcard $(SRC_DIR)*.c)

OBJ		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c $(INCLUDE)
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all:		utils $(NAME)

$(NAME):	$(OBJ)
				$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

fclean:		clean
				$(RM) $(NAME)

clean:		utils
				$(RM) $(OBJ)

utils:
				$(MAKE) $(MAKECMDGOALS) -C utils

re : fclean all

.PHONY: all clean fclean re utils