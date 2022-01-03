/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:16 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/03 15:15:52 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxx.h"

void	mlx_img_init(int x, int y, void *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx, x, y);
	img->addr = mlx_get_data_addr(\
	img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}
