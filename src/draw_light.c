/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:34 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 18:37:16 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_shadow(t_data *data)
{
	t_vec			light_dir;
	t_ray			light_ray;
	t_hit_record	rec;

	light_dir = vec_minus(data->light.spot, data->rec.p);
	light_ray = ray(vec_plus(data->rec.p, \
		vec_mult(data->rec.normal, EPSILON)), light_dir);
	rec.tmin = EPSILON;
	rec.tmax = vec_cal_len(light_dir);
	if (hit(data->first_obj, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color	lighting_diffuse(t_data *data)
{
	t_vec	light_dir;
	double	kd;

	light_dir = vec_minus(data->light.spot, data->rec.p);
	kd = fmax(vec_dot(data->rec.normal, vec_cal_unit(light_dir)), 0.0);
	return (col_mult(color(0, 1, 1, 1), kd));
}

t_color	lighting(t_data *data)
{
	t_color		ambient;
	t_color		diffuse;
	double		brightness;
	t_color		light_color;

	ambient = col_mult(data->ambient.color, data->ambient.ratio);
	if (in_shadow(data))
		light_color = col_multc(ambient, data->rec.color);
	else
	{
		diffuse = lighting_diffuse(data);
		brightness = data->light.ratio * LUMEN;
		light_color = col_multc(col_mult(col_plus(ambient, diffuse), \
			brightness), data->rec.color);
	}
	return (col_min(light_color, color(0, 1, 1, 1)));
}
