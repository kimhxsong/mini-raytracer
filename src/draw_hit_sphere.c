/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hit_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:24 by yookim            #+#    #+#             */
/*   Updated: 2022/02/05 18:28:02 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* a = vec_dot(ray->dir, ray->dir) */
static double	hit_sphere_d(t_sphere *sp, t_ray *ray, t_root type)
{
	double	discriminant;
	t_vec	ce;
	double	a;
	double	half_b;
	double	c;

	ce = vec_minus(ray->orig, sp->center);
	a = 1;
	half_b = vec_dot(ce, ray->dir);
	c = vec_dot(ce, ce) - (sp->radius * sp->radius);
	discriminant = half_b * half_b - a * c;
	if (type == ROOT_SMALL)
		return ((-half_b - sqrt(discriminant)) / a);
	return (discriminant);
}

static void	hit_sphere_rec(double root, t_sphere *sp, t_ray *ray, \
	t_hit_record *rec)
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
		return (FALSE);
	hit_sphere_rec(root, sp, ray, rec);
	return (TRUE);
}
