/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:27 by yookim            #+#    #+#             */
/*   Updated: 2022/01/26 08:19:48 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	int		hit_result;

	hit_result = FALSE;
	if (obj->type == TYPE_SP)
		hit_result = hit_sphere((t_sphere *)obj->info, ray, rec);
	else if (obj->type == TYPE_PL)
		hit_result = hit_plane((t_plane *)obj->info, ray, rec);
	else if (obj->type == TYPE_CY)
		hit_result = hit_cylinder((t_cylinder *)obj->info, ray, rec);
	return (hit_result);
}

int	hit(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	int				hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (obj)
	{
		if (hit_obj(obj, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.color = obj->color;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}
