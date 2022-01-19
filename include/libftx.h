/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 15:40:36 by hyeonsok         ###   ########.fr       */
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
#include <ctype.h>

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
void	ft_fatal(const char *str);
size_t  ft_strvlen(char **strv);
void	ft_strvfree(char *strv[]);
double	ft_atof(char *str);
int		ft_isinscope(double n, double max, double min);
int		ft_issign(int c);
t_color	ft_strtocolor(char *str);
t_vec	ft_strtovec(char *str);

int		ft_isunitvec(t_vec vec);
int		ft_iscolor(t_color color);

#define BUFFER_SIZE 1024

/** libft */
char	*get_next_line(int fd);
char	**ft_split(char *input, const char *sep);

#endif
