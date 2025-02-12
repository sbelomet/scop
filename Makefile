# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:18:10 by sbelomet          #+#    #+#              #
#    Updated: 2025/02/12 13:06:29 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables

NAME		= scop

CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror -g3
GRPHX_LIBS	= -lGL -lX11
VALGRIND	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
ARGS		= 0

# Colors

RED 		= \033[1;91m
YELLOW		= \033[1;93m
GREEN		= \033[1;92m
BLUE		= \033[1;94m
PURPLE		= \033[1;95m
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
MAGENTA		= \033[0;95m
CYAN		= \033[1;96m
WHITE		= \033[0;97m

# Paths

SRC_PATH	= src/
OBJ_PATH	= obj/
LIB_PATH	= lib/
INCLUDE		= -I include/ -I $(LIB_PATH)libft/include/ \
			$(LIB_PATH)glfw-3.4/include

# Files

SRC_FILES = main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
LIBFT	= $(LIB_PATH)libft/libft.a
GLFW	= $(LIB_PATH)glfw-3.4/src

# Commands

all: _libft $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -L$(LIB_PATH)libft -lft -L$(GLFW) -o $(NAME) $(GRPHX_LIBS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CC_FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

_libft:
	@make -C $(LIB_PATH)libft

clean:
	@make clean -C $(LIB_PATH)libft
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

leaks: re
	$(VALGRIND) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re