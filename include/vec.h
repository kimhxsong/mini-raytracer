/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:39:44 by yookim            #+#    #+#             */
/*   Updated: 2022/01/11 17:03:56 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

#include "libftx.h"

typedef struct s_vec t_vec;

struct s_vec {
	double	i;
	double	j;
	double	k;
};

t_vec	vec_plus(t_vec vec, t_vec vec2);
t_vec	vec_minus(t_vec vec, t_vec vec2);
t_vec	vec_mult(t_vec vec, double t);
double	vec_dot(t_vec vec, t_vec vec2);
t_vec	vec_cross(t_vec vec, t_vec vec2);
t_vec	vec_cal_unit(t_vec vec);
double	vec_cal_len(t_vec vec);

#endif
