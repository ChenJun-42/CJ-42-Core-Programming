# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 14:01:19 by jchen2            #+#    #+#              #
#    Updated: 2024/11/12 18:19:59 by jchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = $(wildcard *_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus: $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus