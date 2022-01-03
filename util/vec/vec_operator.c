/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:13:51 by yookim            #+#    #+#             */
/*   Updated: 2022/01/03 18:25:50 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_plus(t_vec *vec, t_vec *vec2)
{
	return ((t_vec){(vec->i + vec2->i, vec->j + vec2->j, vec->k + vec2->k)})
}

t_vec	vec_minus(t_vec *vec, t_vec *vec2)
{
	return ((t_vec){(vec->i - vec2->i, vec->j - vec2->j, vec->k - vec2->k)})
}

t_vec	vec_mult(t_vec *vec, float t)
{
	return((t_vec){(t * vec->i, t * vec->j, t * vec->k)});
}

float	vec_dot(t_vec *vec, t_vec *vec2)
{
	return(vec->i * vec2->i + vec->j * vec2->j + vec->k * vec2->k)
}

t_vec	vec_cross(t_vec *vec, t_vec *vec2)
{
	return ((t_vec){(vec->j * vec2->k - vec->k * vec2->j,
					vec->k * vec2->i - vec->i * vec2->k,
					vec->i * vec2->j - vec->j * vec2->i)});
}
