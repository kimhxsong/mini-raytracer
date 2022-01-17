/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 10:33:37 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFTX_H
# define LIBFTX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// #include "libft.h"
#include "mlx.h"
#include "vec.h"

typedef struct s_win	t_win;
typedef struct s_img	t_img;
typedef struct s_color	t_color;

struct s_win {
	void	*ptr;
	int		width;
	int		height;
};

struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
};

// double로 바꿈
struct s_color {
	double t;
	double r;
	double g;
	double b;
};

/** mlx extenstion */
void	mlx_img_init(void *mlx_ptr, t_win *win, t_img *img);
void    mlx_img_pixel_put(t_img *img, int color, int x, int y);
int		convert_rgb(t_color color);

/** libft extension */
void	ft_error(char *str);
void	ft_strvfree(char *strv[]);

#define BUFFER_SIZE 1024

/** libft */
char	*get_next_line(int fd);
char	**ft_split(char *input, const char *sep);

#endif
