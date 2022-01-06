/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 19:10:49 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MLXX_H
# define MLXX_H

#include "mlx.h"

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

struct s_color {
	int	t;
	int	r;
	int	g;
	int	b;
};

void	mlx_img_pixel_put(t_img *img, t_color *color, int x, int y);
void	mlx_img_init(void *mlx_ptr, t_win *win, t_img *img);
int		mlx_pixel_color(t_color *color);

#endif