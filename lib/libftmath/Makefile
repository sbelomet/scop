# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 11:54:51 by sbelomet          #+#    #+#              #
#    Updated: 2025/10/21 14:29:39 by sbelomet         ###   ########.fr        #
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
ANG_DIR		=	angles/
OBJS_DIR	=	objs/

F_MTRX		=	mtrx_new mtrx_print mtrx_add mtrx_sub mtrx_mul mtrx_transforms mtrx_projections
F_VCTR		=	vctr_new vctr_print vctr_add vctr_sub vctr_mul vctr_div vctr_len vctr_dot vctr_cross vctr_normalize
F_ANG		=	ang_conv

FILES		=	$(addprefix $(MTRX_DIR), $(F_MTRX)) \
				$(addprefix $(VCTR_DIR), $(F_VCTR)) \
				$(addprefix $(ANG_DIR), $(F_ANG)) \

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
			@mkdir -p $(OBJS_DIR)$(ANG_DIR)

clean:
		@$(RM) $(OBJS_DIR)

fclean:		clean
		@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
