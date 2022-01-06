/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:13:40 by yookim            #+#    #+#             */
/*   Updated: 2022/01/06 20:16:22 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_cal_unit(t_vec vec)
{
	double	len;
	t_vec	unit;

	len = vec_cal_len(vec);
	unit.i = vec.i / len;
	unit.j = vec.j / len;
	unit.k = vec.k / len;
	return (unit);
}

double	vec_cal_len(t_vec vec)
{
	return (sqrt(powf(vec.i, 2) + powf(vec.j, 2) + powf(vec.k, 2)));
}
