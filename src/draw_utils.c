/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:24:11 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 14:35:47 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_ray	ray(t_point orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_cal_unit(dir);
	return (ray);
}
