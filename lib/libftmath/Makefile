# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 11:54:51 by sbelomet          #+#    #+#              #
#    Updated: 2025/02/18 15:47:43 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftmath.a

GCC			=	gcc
AR			=	ar rc
RM			=	rm -rf
LIB			=	ranlib
HEADER		=	-I include
CFLAGS		=	-Wall -Wextra -Werror

MTRX_DIR	=	matrices/
VCTR_DIR	=	vectors/
OBJS_DIR	=	objs/

F_MTRX		=	mtrx_new mtrx_print mtrx_add mtrx_sub
F_VCTR		=	vctr_new vctr_print vctr_add vctr_sub vctr_mul vctr_div vctr_len vctr_dot vctr_cross vctr_normalize

FILES		=	$(addprefix $(MTRX_DIR), $(F_MTRX)) \
				$(addprefix $(VCTR_DIR), $(F_VCTR)) \

SRCS		=	$(addsuffix .c, $(FILES)) \

OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES))) \

all:		$(OBJS_DIR) $(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@$(LIB) $(NAME)

$(OBJS_DIR)%.o: %.c
	@$(GCC) $(CFLAGS) -o $@ -c $< $(HEADER)

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(MTRX_DIR)
			@mkdir -p $(OBJS_DIR)$(VCTR_DIR)

clean:
		@$(RM) $(OBJS_DIR)

fclean:		clean
		@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
