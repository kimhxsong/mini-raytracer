/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:13:40 by yookim            #+#    #+#             */
/*   Updated: 2022/01/03 18:24:28 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_cal_unit(t_vec *vec)
{
	float len;

	len = vec_cal_len(vec);
	return ((t_vec){(vec->i / len, vec->j / len, vec->k / len)});
}

float	vec_cal_len(t_vec *vec)
{
	return (sqrt(powf(vec->i, 2) + powf(vec->j, 2) + powf(vec->k, 2)));
}
