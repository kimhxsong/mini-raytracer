/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:34 by yookim            #+#    #+#             */
/*   Updated: 2022/01/26 06:57:53 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_shadow(t_data *data)
{
	t_vec			light_dir;
	double			light_len;
	t_ray			light_ray;
	t_hit_record	rec;

	light_dir = vec_minus(data->light.spot, data->rec.p);
	light_len = vec_cal_len(light_dir);
	light_ray = ray(vec_plus(data->rec.p, \
		vec_mult(data->rec.normal, EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
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
	t_color		light_color;
	t_color		ambient;
	t_color		diffuse;
	double		brightness;

	if (in_shadow(data))
		return (color(0, 0, 0, 0));
	ambient = col_mult(data->ambient.color, data->ambient.ratio);
	diffuse = lighting_diffuse(data);
	brightness = data->light.ratio * LUMEN;
	light_color = col_mult(col_plus(ambient, diffuse), brightness);
	return (col_min(col_multc(light_color, data->rec.color), \
		color(0, 1, 1, 1)));
}
