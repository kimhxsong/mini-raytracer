/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:24:11 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/03 17:59:27 by hyeonsok         ###   ########.fr       */
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

t_point	ray_to(t_ray *ray, double t)
{
	t_point	at;

	at = vec_plus(ray->orig, vec_mult(ray->dir, t));
	return (at);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vec_mult(rec->normal, -1);
}
