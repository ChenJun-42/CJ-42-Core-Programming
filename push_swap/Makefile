# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 18:15:18 by jchen2            #+#    #+#              #
#    Updated: 2025/01/04 14:06:24 by jchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
FTPRINTF = libftprintf.a
SRCS = create_stack.c \
		free_stack.c \
		init_stack.c \
		input_string_valid.c \
		input_valid.c \
		main.c \
		print_stack.c \
		push_ab.c \
		rotate_ab.c \
		rotate_reverse_ab.c \
		sort_stack.c \
		swap_ab.c \
		renew_step_node.c \
		a_to_b.c \
		b_to_a.c \
		find_ministep.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) -g -o $(NAME)

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
