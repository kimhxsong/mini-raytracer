/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:39:44 by yookim            #+#    #+#             */
/*   Updated: 2022/01/03 17:44:52 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

#include "minirt.h"

typedef struct s_coordinates t_coordinates;
typedef struct s_vec t_vec;

struct s_coordinates {
	int	x;
	int	y;
	int	z;
};

struct s_vec {
	float	x;
	float	y;
	float	z;
};

t_vec	vec_plus(t_vec *vec, t_vec *vec2);
t_vec	vec_minus(t_vec *vec, t_vec *vec2);
t_vec	vec_mult(t_vec *vec, float t);
float	vec_dot(t_vec *vec, t_vec *vec2);
t_vec	vec_cross(t_vec *vec, t_vec *vec2);
t_vec	vec_cal_unit(t_vec *vec);
float	vec_cal_len(t_vec *vec);

#endif
