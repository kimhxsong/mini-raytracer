/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:16 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 17:07:42 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxx.h"

void	mlx_img_init(t_data *data)
{
	t_win	*win;
	t_img	*img;

	win = &data->win;
	img = &data->img;
	img->image = mlx_new_image(data->mlx_ptr, win->width, win->height);
	img->address = mlx_get_data_addr(\
	img->ptr, &img->bpp, &img->width, &img->endian);
}
