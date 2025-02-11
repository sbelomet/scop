# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:18:10 by sbelomet          #+#    #+#              #
#    Updated: 2025/02/11 13:34:05 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= scop

CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror -g3
GRPHX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_PATH	= src/
INC_PATH	= include/
OBJ_PATH	= obj/
LIB_PATH	= lib/

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

# Commands

all: build run

build:
	@echo "$(BLUE)Building container...$(DEF_COLOR)"
	@docker build -t $(NAME) .
	@echo "$(GREEN)Container successfully built!$(DEF_COLOR)"

run:
	@echo "$(BLUE)Running program...$(DEF_COLOR)"
	@docker run -it --rm --name my-running-app $(NAME)
	@echo "$(GREEN)Program ended!$(DEF_COLOR)"

.PHONY: all build run