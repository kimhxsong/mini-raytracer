# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:45:59 by hyeonsok          #+#    #+#              #
#    Updated: 2022/01/03 15:25:20 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc -g3
# CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./include/ -I ./lib/minilibx_opengl_20191021/
MLX = -lmlx -L ./lib/minilibx_opengl_20191021/ -framework OpenGL -framework AppKit
LIBS = $(MLX)

SRCDIR := ./src
UTILDIR := ./util
OBJDIR := ./obj
OBJS	= $(addprefix $(OBJDIR)/, \
			main.o)

NAME = miniRT

.PHONY:		all
all:		mlx $(NAME)

.PHONY:		mlx
mlx:
			make -C ./lib/minilibx_opengl_20191021/

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			$(CC) $(INCLUDES) $(LIBS) $(CFLAGS) -c $< -o $@

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