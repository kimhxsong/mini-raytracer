/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hit_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:24 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 21:39:02 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_sphere_d(t_sphere *sp, t_ray *ray, t_root type)
{
	double	discriminant;
	t_vec	co;
	double	a;
	double	half_b;
	double	c;

	co = vec_minus(ray->orig, sp->center);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(co, ray->dir);
	c = vec_dot(co, co) - (sp->radius * sp->radius);
	discriminant = half_b * half_b - a * c;
	if (type == ROOT_SMALL)
		return ((-half_b - sqrt(discriminant)) / a);
	if (type == ROOT_BIG)
		return ((-half_b + sqrt(discriminant)) / a);
	return (discriminant);
}

void	hit_sphere_rec(double root, t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	rec->t = root;
	rec->p = ray_to(ray, root);
	rec->normal = vec_cal_unit(vec_minus(rec->p, sp->center));
	set_face_normal(ray, rec);
}

int	hit_sphere(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	double		discriminant;
	double		root;
	t_sphere	*sp;

	sp = (t_sphere *)obj->info;
	discriminant = hit_sphere_d(sp, ray, DISCRIMINANT);
	if (discriminant < 0)
		return (FALSE);
	root = hit_sphere_d(sp, ray, ROOT_SMALL);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = hit_sphere_d(sp, ray, ROOT_BIG);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	hit_sphere_rec(root, sp, ray, rec);
	return (TRUE);
}
