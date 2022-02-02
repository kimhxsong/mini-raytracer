/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:50 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 13:05:39 by hyeonsok         ###   ########.fr       */
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

typedef struct s_obj	t_obj;
typedef struct s_sphere	t_sphere;
typedef struct s_ray	t_ray;
typedef struct s_plane	t_plane;
typedef struct s_scene	t_scene;

int		hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_point	ray_to(t_ray *ray, double t);
int		hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
int		hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int		hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec);

#endif
