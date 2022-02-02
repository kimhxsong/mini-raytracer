/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hit_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:20 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 16:06:20 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hit_plane_rec(double root, t_plane *pl, t_ray *ray, t_hit_record * rec)
{
	rec->t = root;
	rec->p = ray_to(ray, root);
	rec->normal = pl->normal;
	set_face_normal(ray, rec);
}

int	hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	t_vec	oc;
	double	denominator;
	double	root;

	oc = vec_minus(pl->center, ray->orig);
	denominator = vec_dot(ray->dir, pl->normal);
	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	root = vec_dot(oc, pl->normal) / denominator;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	hit_plane_rec(root, pl, ray, rec);
	return (TRUE);
}
