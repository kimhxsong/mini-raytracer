/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:31:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 14:22:05 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(double t, double r, double g, double b)
{
	t_color	color;

	color.t = t;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	col_mult(t_color col1, double t)
{
	t_color	color;

	color.t = col1.t * t;
	color.r = col1.r * t;
	color.g = col1.g * t;
	color.b = col1.b * t;
	return (color);
}

t_color	col_plus(t_color col1, t_color col2)
{
	t_color	color;

	color.t = col1.t + col2.t;
	color.r = col1.r + col2.r;
	color.g = col1.g + col2.g;
	color.b = col1.b + col2.b;
	return (color);
}

t_color	col_min(t_color col1, t_color col2)
{
	col1.t = 0;
	if (col1.r > col2.r)
		col1.r = col2.r;
	if (col1.g > col2.g)
		col1.g = col2.g;
	if (col1.b > col2.b)
		col1.b = col2.b;
	return (col1);
}

t_color	col_multc(t_color c1, t_color c2)
{
	c1.t *= c2.t;
	c1.r *= c2.r;
	c1.g *= c2.g;
	c1.b *= c2.b;
	return (c1);
}
