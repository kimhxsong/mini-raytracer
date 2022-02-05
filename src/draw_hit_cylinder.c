/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hit_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:16 by yookim            #+#    #+#             */
/*   Updated: 2022/02/05 18:30:48 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* a = vec_dot(ray->dir, ray->dir) - pow(vec_dot(ray->dir, cy->normal), 2); */
static double	hit_cylinder_d(t_cylinder *cy, t_ray *ray, t_root type)
{
	double	discriminant;
	t_vec	ce;
	double	a;
	double	half_b;
	double	c;

	ce = vec_minus(ray->orig, cy->center);
	a = 1 - pow(vec_dot(ray->dir, cy->normal), 2);
	half_b = vec_dot(ray->dir, ce) \
		- (vec_dot(ray->dir, cy->normal) * vec_dot(ce, cy->normal));
	c = vec_dot(ce, ce) - pow(vec_dot(ce, cy->normal), 2) \
		- (cy->radius * cy->radius);
	discriminant = half_b * half_b - a * c;
	if (type == ROOT_SMALL)
		return ((-half_b - sqrt(discriminant)) / a);
	if (type == ROOT_BIG)
		return ((-half_b + sqrt(discriminant)) / a);
	return (discriminant);
}

static int	hit_cylinder_h(double root, t_cylinder *cy, t_ray *ray, \
	t_hit_record *rec)
{
	t_point	p;
	double	h_range;

	p = ray_to(ray, root);
	h_range = vec_dot(vec_minus(p, cy->center), cy->normal);
	if (h_range < 0 || h_range > cy->height)
		return (FALSE);
	rec->t = root;
	rec->p = p;
	rec->normal = vec_cal_unit(vec_minus(p, \
		vec_plus(cy->center, vec_mult(cy->normal, h_range))));
	set_face_normal(ray, rec);
	return (TRUE);
}

static int	hit_cylinder_rootb(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	root;

	root = hit_cylinder_d(cy, ray, ROOT_BIG);
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	if (!hit_cylinder_h(root, cy, ray, rec))
		return (FALSE);
	return (TRUE);
}

static int	hit_cylinder_root(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	root;

	root = hit_cylinder_d(cy, ray, ROOT_SMALL);
	if (root < rec->tmin || rec->tmax < root)
		return (hit_cylinder_rootb(cy, ray, rec));
	else if (!hit_cylinder_h(root, cy, ray, rec))
		return (hit_cylinder_rootb(cy, ray, rec));
	return (TRUE);
}

int	hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	double		discriminant;
	t_cylinder	*cy;

	cy = (t_cylinder *)obj->info;
	discriminant = hit_cylinder_d(cy, ray, DISCRIMINANT);
	if (discriminant < 0)
		return (FALSE);
	if (!hit_cylinder_root(cy, ray, rec))
		return (FALSE);
	return (TRUE);
}
