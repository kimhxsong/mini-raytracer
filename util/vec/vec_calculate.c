/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:13:40 by yookim            #+#    #+#             */
/*   Updated: 2022/01/03 17:38:23 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_cal_unit(t_vec *vec)
{
	float len;

	len = vec_cal_len(vec);
	return ((t_vec){(vec->x / len, vec->y / len, vec->z / len)});
}

float	vec_cal_len(t_vec *vec)
{
	return (sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
}
