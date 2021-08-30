# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 14:55:10 by jbadia            #+#    #+#              #
#    Updated: 2021/08/30 12:00:16 by jbadia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft
MAKELIBFT = $(MAKE) -C $(LIBFT)

SRCS_DIR = srcs
OBJ_DIR = obj
HDRS = include

CFILES = push_swap.c check_error.c func_free.c swap_op.c push_op.c \
		rotate_op.c reverse_rotate_op.c resolve.c sort_small.c sort_big.c\
		quicksort.c utils_sort.c utils.c \
		
OFILES = $(CFILES:.c=.o)

SRCS = $(addprefix $(SRCS_DIR)/, $(CFILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OFILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


$(OBJ_DIR)/%.o :	$(SRCS_DIR)/%.c
	${CC} ${CFLAGS} -I ${HDRS} -I $(LIBFT) -c $< -o $@ 
	

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKELIBFT)
	$(CC) $(OBJS) -L $(LIBFT) -lft -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

all :	$(NAME)

clean :
	$(MAKELIBFT) clean
	$(RM) $(OBJS)
	
fclean :	clean
	$(MAKELIBFT) fclean
	$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re