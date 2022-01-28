/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:10 by yookim            #+#    #+#             */
/*   Updated: 2022/01/26 04:47:35 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_point orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_cal_unit(dir);
	return (ray);
}

t_color	color(double t, double r, double g, double b)
{
	t_color	color;

	color.t = t;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_hit_record	record_init(void)
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
	while (++j < WIN_SIZE_Y)
	{
		i = -1;
		while (++i < WIN_SIZE_X)
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

// t = (double) j / WIN_SIZE_Y; // 임시 배경
// pixel_color = col_plus(col_mult(color(0, 1, 1, 1), t), col_mult(color(0, 0.5, 0.7, 1), 1 - t));
