/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:10 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 20:23:59 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

void	draw_scene(t_data *data)
{
	t_scene	scene;
	int		i;
	int		j;
	t_color	pixel_color;

	scene = data->scene;
	j = -1;
	while (++j < data->win.height)
	{
		i = -1;
		while (++i < data->win.width)
		{
			data->ray = ray(scene.cam.origin, scene.view.matrix[j][i]);
			data->rec = record_init();
			if (hit(data->first_obj, &data->ray, &data->rec))
				pixel_color = lighting(data);
			else
				pixel_color = color(0, 0, 0, 0);
			mlx_img_pixel_put(&data->img, convert_rgb(pixel_color), i, j);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win.ptr, data->img.ptr, 0, 0);
}
