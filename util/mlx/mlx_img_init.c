/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:16 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 17:26:21 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxx.h"

void	mlx_img_init(void *mlx_ptr, t_win *win, t_img *img)
{
	img->ptr = mlx_new_image(mlx_ptr, win->width, win->height);
	img->addr = mlx_get_data_addr(\
		img->ptr, &img->bpp, &img->width, &img->endian);
}
