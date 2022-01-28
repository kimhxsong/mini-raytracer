/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:16 by yookim            #+#    #+#             */
/*   Updated: 2022/01/26 06:55:21 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_cylinder_d(t_cylinder *cy, t_ray *ray, t_root type)
{
	double	discriminant;
	t_vec	co;
	double	a;
	double	half_b;
	double	c;

	co = vec_minus(ray->orig, cy->center);
	a = vec_dot(ray->dir, ray->dir) - pow(vec_dot(ray->dir, cy->normal), 2);
	half_b = vec_dot(ray->dir, co)
		- (vec_dot(ray->dir, cy->normal) * vec_dot(co, cy->normal));
	c = vec_dot(co, co) - pow(vec_dot(co, cy->normal), 2)
		- (cy->radius * cy->radius);
	discriminant = half_b * half_b - a * c;
	if (type == ROOT_SMALL)
		return ((-half_b - sqrt(discriminant)) / a);
	if (type == ROOT_LARGE)
		return ((-half_b + sqrt(discriminant)) / a);
	return (discriminant);
}

int	hit_cylinder_h(double root, t_cylinder *cy, t_ray *ray, t_hit_record *rec)
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

int	hit_cylinder_root(double d, t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	root;

	root = hit_cylinder_d(cy, ray, ROOT_SMALL);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = hit_cylinder_d(cy, ray, ROOT_LARGE);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
		if (!hit_cylinder_h(root, cy, ray, rec))
			return (FALSE);
	}
	else
	{
		if (!hit_cylinder_h(root, cy, ray, rec))
		{
			root = hit_cylinder_d(cy, ray, ROOT_LARGE);
			if (root < rec->tmin || rec->tmax < root)
				return (FALSE);
			if (!hit_cylinder_h(root, cy, ray, rec))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	discriminant;

	discriminant = hit_cylinder_d(cy, ray, DISCRIMINANT);
	if (discriminant < 0)
		return (FALSE);
	if (!hit_cylinder_root(discriminant, cy, ray, rec))
		return (FALSE);
	return (TRUE);
}
