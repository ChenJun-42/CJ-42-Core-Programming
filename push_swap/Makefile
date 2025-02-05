# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 18:15:18 by jchen2            #+#    #+#              #
#    Updated: 2025/02/01 15:29:32 by jchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I libft -I ft_printf

SRC_DIR = srcs
BUILD_DIR = build
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
INCLUDE_DIR = include

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRCS = create_stack.c \
	free_stack.c \
	init_stack.c \
	input_string_valid.c \
	input_valid.c \
	free_split.c \
	is_num.c \
	init_num_index.c \
	main.c \
	push_ab.c \
	rotate_ab.c \
	rotate_reverse_ab.c \
	sort_stack.c \
	swap_ab.c \
	renew_step_node.c \
	a_to_b.c \
	ex_same_down.c \
	ex_same_up.c \
	ex_ops_down.c \
	ex_ops_up.c \
	b_to_a.c \
	find_ministep.c \
	is_sorted.c \
	sort_three_node.c \
	sort_four_node.c \
	sort_five_node.c \
	sep_grp.c \
	p_b_a.c \
	renew_step_node_group.c \
	ex_ops_down_b_a.c \
	ex_ops_up_b_a.c \
	ex_same_down_b_a.c \
	ex_same_up_b_a.c \
	rotate_min_top.c
	
OBJS = $(SRCS:.c=.o)
OBJ_PATHS = $(OBJS:%=$(BUILD_DIR)/%)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_PATHS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PATHS) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*.o
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
