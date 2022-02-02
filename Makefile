# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:45:59 by hyeonsok          #+#    #+#              #
#    Updated: 2022/02/02 12:35:36 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I./include/ -I./lib/minilibx_opengl_20191021/ -I./lib/libft/include/
MLX	= -lmlx -framework OpenGL -framework AppKit -L./lib/minilibx_opengl_20191021/
FT = -lft -L./lib/libft
LIBS = $(MLX) $(FT)

SRCDIR := ./src
UTILDIR := ./util
UTIL_MLX_DIR := ./util/mlx
UTIL_VEC_DIR := ./util/vec
UTIL_COL_DIR := ./util/color

OBJDIR := ./obj
OBJS	= $(addprefix $(OBJDIR)/, \
			main.o \
			init_data.o \
			init_scene.o \
			parse.o \
			parse_ambient.o \
			parse_camera.o \
			parse_cylinder.o \
			parse_light.o \
			parse_plane.o \
			parse_sphere.o \
			parse_util.o \
			listen_event.o \
			get_next_line.o \
			ft_strvfree.o \
			ft_error.o \
			ft_fatal.o \
			ft_strtocolor.o \
			ft_strtovec.o \
			ft_strvlen.o \
			ft_iscolor.o \
			ft_isunitvec.o \
			ft_isinscope.o \
			ft_atof.o \
			mlx_img_pixel_put.o \
			convert_rgb.o \
			vec_calculate.o \
			vec_operator.o \
			draw.o \
			hit.o \
			light.o \
			hit_cylinder.o\
			hit_plane.o \
			hit_sphere.o \
			color_operator.o)

NAME = miniRT

.PHONY:		all
all:		libft mlx $(NAME)

.PHONY:		libft
libft:
			@make -C ./lib/libft
.PHONY:		mlx
mlx:
			@make -C ./lib/minilibx_opengl_20191021/

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR)/%.c
			@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTIL_MLX_DIR)/%.c
			@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTIL_VEC_DIR)/%.c
			@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTIL_COL_DIR)/%.c
			@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY:		NAME
$(NAME):	$(OBJDIR) $(OBJS)
			@$(CC) $(INCLUDES) $(LIBS) $(OBJS) -o $(NAME)

$(OBJS): | $(OBJDIR)
$(OBJDIR):
			@mkdir $(OBJDIR)

.PHONY:		clean
clean:
			@$(RM) -r $(OBJDIR)

.PHONY:		fclean
fclean:		clean
			@make clean -C ./lib/minilibx_opengl_20191021/
			@make clean -C ./lib/libft
			@$(RM) -r $(NAME)

.PHONY:		re
re:
			@$(MAKE) fclean
			@$(MAKE)
