# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 13:21:07 by jchen2            #+#    #+#              #
#    Updated: 2025/01/31 10:57:14 by jchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I include -I libft -I minilibx-linux
LDFLAGS = -lX11 -lXext -lm

SRCDIR = srcs
LIBFTDIR = libft
MLXDIR = minilibx-linux
BUILDDIR = build

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx_Linux.a

SRCS = $(SRCDIR)/inital_data.c \
	$(SRCDIR)/convert_file.c \
	$(SRCDIR)/count_rows_cols.c \
	$(SRCDIR)/set_height_color.c \
	$(SRCDIR)/projection.c \
	$(SRCDIR)/translation.c \
	$(SRCDIR)/rotation.c \
	$(SRCDIR)/isometric_projection.c \
	$(SRCDIR)/top_projection.c \
	$(SRCDIR)/conic_projection.c \
	$(SRCDIR)/front_projection.c \
	$(SRCDIR)/side_projection.c \
	$(SRCDIR)/set_osx_osy.c \
	$(SRCDIR)/draw_img.c \
	$(SRCDIR)/draw_grid.c \
	$(SRCDIR)/bresenham_line.c \
	$(SRCDIR)/reset.c \
	$(SRCDIR)/free_data.c \
	$(SRCDIR)/get_next_line.c \
	$(SRCDIR)/get_next_line_utils.c \
	$(SRCDIR)/main.c \
	$(SRCDIR)/cal_x_offset.c \
	$(SRCDIR)/cal_y_offset.c \
	$(SRCDIR)/zoom.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	
clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(BUILDDIR)
	make -C $(LIBFTDIR) fclean
	make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(MLX)
