/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:50 by yookim            #+#    #+#             */
/*   Updated: 2022/01/26 07:03:38 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H
# include "vec.h"

typedef enum e_root {
	DISCRIMINANT,
	ROOT_SMALL,
	ROOT_LARGE
}	t_root;

int		hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_point	ray_to(t_ray *ray, double t);
int		hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
int		hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int		hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec);

#endif
