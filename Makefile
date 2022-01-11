# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:45:59 by hyeonsok          #+#    #+#              #
#    Updated: 2022/01/11 18:10:21 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc -g3
# CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I./include/ -I./lib/minilibx_opengl_20191021/
MLX = -lmlx -framework OpenGL -framework AppKit -L./lib/minilibx_opengl_20191021/
LIBS = $(MLX)

SRCDIR := ./src
UTILDIR := ./util
UTIL_MLX_DIR := ./util/mlx
UTIL_VEC_DIR := ./util/vec

OBJDIR := ./obj
OBJS	= $(addprefix $(OBJDIR)/, \
			main.o \
			init_data.o \
			init_cam.o \
			parse.o \
			parse_obj.o \
			parse_uni.o \
			listen_event.o \
			get_next_line.o \
			ft_error.o \
			ft_split.o \
			mlx_img_pixel_put.o \
			mlx_pixel_color.o \
			vec_calculate.o \
			vec_operator.o)

NAME = miniRT

.PHONY:		all
all:		mlx $(NAME)

.PHONY:		mlx
mlx:
			make -C ./lib/minilibx_opengl_20191021/

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTIL_MLX_DIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTIL_VEC_DIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY:		NAME
$(NAME):	$(OBJDIR) $(OBJS)
			$(CC) $(INCLUDES) $(LIBS) $(OBJS) -o $(NAME)

$(OBJS): | $(OBJDIR)
$(OBJDIR):
			mkdir $(OBJDIR)

.PHONY:		clean
clean:
			$(RM) -r $(OBJDIR)

.PHONY:		fclean
fclean:		clean
			make clean -C ./lib/minilibx_opengl_20191021/
			$(RM) -r $(NAME)

.PHONY:		re
re:
			$(MAKE) fclean
			$(MAKE)