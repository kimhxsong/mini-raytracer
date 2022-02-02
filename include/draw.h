/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:46 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 14:46:10 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "parse.h"

typedef enum e_root {
	DISCRIMINANT,
	ROOT_SMALL,
	ROOT_LARGE
}	t_root;

/**
 * light.c
 */
t_color	lighting(t_data *data);

/**
 * hit.*
 */
int		hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_point	ray_to(t_ray *ray, double t);
int		hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
int		hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int		hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec);

/**
 * draw.c
 */
void	draw_scene(t_data *data);

/**
 * utils
 */
t_ray	ray(t_point orig, t_vec dir);

#endif
