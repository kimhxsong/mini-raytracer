/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:13:51 by yookim            #+#    #+#             */
/*   Updated: 2022/01/03 17:26:17 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_plus(t_vec *vec, t_vec *vec2)
{
	return ((t_vec){(vec->x + vec2->x, vec->y + vec2->y, vec->z + vec2->z)})
}

t_vec	vec_minus(t_vec *vec, t_vec *vec2)
{
	return ((t_vec){(vec->x - vec2->x, vec->y - vec2->y, vec->z - vec2->z)})
}

t_vec	vec_mult(t_vec *vec, float t)
{
	return((t_vec){(t * vec->x, t * vec->y, t * vec->z)});
}

float	vec_dot(t_vec *vec, t_vec *vec2)
{
	return(vec->x * vec2->x + vec->y * vec2->y + vec->z * vec2->z)
}

t_vec	vec_cross(t_vec *vec, t_vec *vec2)
{
	return ((t_vec){(vec->y * vec2->z - vec->z * vec2->y,
					vec->z * vec2->x - vec->x * vec2->z,
					vec->x * vec2->y - vec->y * vec2->x)});
}
