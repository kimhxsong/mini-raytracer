/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 17:09:21 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MLXX_H
# define MLXX_H

#include "mlx.h"

typedef struct s_mlx	t_mlx;
typedef struct s_color	t_color;
typedef struct s_img	t_img;

struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
};

struct s_win {
	void	*ptr;
	int		width;
	int		height;
}
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