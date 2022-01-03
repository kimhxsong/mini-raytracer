/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/03 15:22:20 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MLXX_H
# define MLXX_H

#include "mlx.h"

typedef struct s_mlx	t_mlx;
typedef struct s_color	t_color;
typedef struct s_img	t_img;

struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	t_img	*img_ptr;
};

struct t_img {
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct t_color {
	float	t;
	float	r;
	float	g;
	float	b;
};

void	mlx_img_pixel_put(t_img *img, int x, int y, int color);
void	mlx_img_init(int x, int y, void *mlx, t_img *img);
int		mlx_img_pixel_color(t_color *color);

#endif