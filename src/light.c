/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:34 by yookim            #+#    #+#             */
/*   Updated: 2022/01/19 02:09:34 by yookim           ###   ########.fr       */
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
	light_ray = ray(vec_plus(data->rec.p, vec_mult(data->rec.normal, EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(data->first_obj, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color	lighting_diffuse(t_data *data)
{
	t_vec light_dir;
	double kd;

	light_dir = vec_minus(data->light.spot, data->rec.p);
	kd = fmax(vec_dot(data->rec.normal, vec_cal_unit(light_dir)), 0.0);
	return (vec_mult_c(color(0, 1, 1, 1), kd));
}

t_color	lighting(t_data *data)
{
	t_color		light_color;
	t_color		ambient;
	t_color		diffuse;
	double		brightness;

	if (in_shadow(data))
		return (color(0, 0, 0, 0));
	ambient = vec_mult_c(color(0, 1, 1, 1), data->ambient.ratio);
	diffuse = lighting_diffuse(data);
	brightness = data->light.ratio * LUMEN;
	light_color = vec_mult_c(vec_plus_c(ambient, diffuse), brightness);
	return (vec_min(vec_multc(light_color, data->rec.color), color(0, 1, 1, 1)));
}

// 아래 4개의 함수는 t_color의 t_vec으로 통일이 되면 없어진다.
t_color	vec_mult_c(t_color col1, double t)
{
	t_color	color;

	color.t = col1.t * t;
	color.r = col1.r * t;
	color.g = col1.g * t;
	color.b = col1.b * t;
	return (color);
}

t_color	vec_plus_c(t_color col1, t_color col2)
{
	t_color	color;

	color.t = col1.t + col2.t;
	color.r = col1.r + col2.r;
	color.g = col1.g + col2.g;
	color.b = col1.b + col2.b;
	return (color);
}

t_color	vec_min(t_color col1, t_color col2)
{
	col1.t = 0;
	if (col1.r > col2.r)
		col1.r = col2.r;
	if (col1.g > col2.g)
		col1.g = col2.g;
	if (col1.b > col2.b)
		col1.b = col2.b;
	return (col1);
}

t_color	vec_multc(t_color c1, t_color c2)
{
	c1.t *= c2.t;
	c1.r *= c2.r;
	c1.g *= c2.g;
	c1.b *= c2.b;
	return (c1);
}
