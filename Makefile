# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:45:59 by hyeonsok          #+#    #+#              #
#    Updated: 2022/02/05 17:54:20 by yookim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I./include/ -I./lib/minilibx_opengl_20191021/ -I./lib/libft/include/
MLX	= -lmlx -framework OpenGL -framework AppKit -L./lib/minilibx_opengl_20191021/
FT = -lft -L./lib/libft
LIBS = $(MLX) $(FT)

LIBFT = lib/libft/libft.a
LIBMLX = lib/minilibx_opengl_20191021/libmlx.a

SRCDIR := ./src
UTILDIR := ./util
UTILDIR_MLX := ./util/mlx
UTILDIR_VEC := ./util/vec
UTILDIR_COLOR := ./util/color

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
			ft_strdupnl.o \
			ft_strjoinnl.o \
			mlx_img_pixel_put.o \
			convert_rgb.o \
			vec_calculate.o \
			vec_operator.o \
			draw.o \
			draw_utils.o \
			draw_hit.o \
			draw_light.o \
			draw_hit_cylinder.o\
			draw_hit_plane.o \
			draw_hit_sphere.o \
			color_utils.o)

NAME = miniRT

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR_MLX)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR_VEC)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR_COLOR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@


.PHONY:		all
all:		libft mlx $(NAME)

.PHONY:		libft
libft:		$(LIBFT)

.PHONY:		mlx
mlx:		$(LIBMLX)

$(NAME):	$(OBJS)
			$(CC) $(INCLUDES) $(LIBS) $(OBJS) -o $(NAME)

$(LIBFT):
			make -C ./lib/libft

$(LIBMLX):
			make -C ./lib/minilibx_opengl_20191021/

$(OBJS): | $(OBJDIR)
$(OBJDIR):
			mkdir $(OBJDIR)

.PHONY:		clean
clean:
			make clean -C ./lib/libft
			$(RM) -r $(OBJDIR)

.PHONY:		fclean
fclean:		clean
			make clean -C ./lib/minilibx_opengl_20191021/
			make fclean -C ./lib/libft
			$(RM) -r $(NAME)

.PHONY:		re
re:
			$(MAKE) fclean
			$(MAKE)
