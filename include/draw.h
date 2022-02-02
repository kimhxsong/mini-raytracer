/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:46 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 21:38:01 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "parse.h"

typedef enum e_root {
	DISCRIMINANT,
	ROOT_SMALL,
	ROOT_BIG
}	t_root;

typedef struct s_hit {
	int (*fn)(t_obj *, t_ray *, t_hit_record *);
} t_hit;

/**
 * light.c
 */
t_color	lighting(t_data *data);

/**
 * hit.*
 */
int		hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
int		hit_sphere(t_obj *obj, t_ray *ray, t_hit_record *rec);
int		hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec);
int		hit_plane(t_obj *obj, t_ray *ray, t_hit_record *rec);

/**
 * draw.c
 */
void	draw_scene(t_data *data);

/**
 * utils
 */
t_ray	ray(t_point orig, t_vec dir);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_point	ray_to(t_ray *ray, double t);

#endif
