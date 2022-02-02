/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:13:51 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 13:02:40 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_plus(t_vec vec1, t_vec vec2)
{
	t_vec	vec;

	vec.i = vec1.i + vec2.i;
	vec.j = vec1.j + vec2.j;
	vec.k = vec1.k + vec2.k;
	return (vec);
}

t_vec	vec_minus(t_vec vec1, t_vec vec2)
{
	t_vec	vec;

	vec.i = vec1.i - vec2.i;
	vec.j = vec1.j - vec2.j;
	vec.k = vec1.k - vec2.k;
	return (vec);
}

t_vec	vec_mult(t_vec vec1, double t)
{
	t_vec	vec;

	vec.i = vec1.i * t;
	vec.j = vec1.j * t;
	vec.k = vec1.k * t;
	return (vec);
}

double	vec_dot(t_vec vec1, t_vec vec2)
{
	return (vec1.i * vec2.i + vec1.j * vec2.j + vec1.k * vec2.k);
}

t_vec	vec_cross(t_vec vec1, t_vec vec2)
{
	t_vec	vec;

	vec.i = vec1.j * vec2.k - vec1.k * vec2.j;
	vec.j = vec1.k * vec2.i - vec1.i * vec2.k;
	vec.k = vec1.i * vec2.j - vec1.j * vec2.i;
	return (vec);
}
