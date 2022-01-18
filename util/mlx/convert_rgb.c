/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:19:22 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 02:08:27 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int		convert_rgb(t_color color)
{
	int t;
	int	r;
	int	g;
	int	b;

	t = (int)(color.t * 255.999);
	r = (int)(color.r * 255.999);
	g = (int)(color.g * 255.999);
	b = (int)(color.b * 255.999);
	return (t << 24 | r << 16 | g << 8 | b);
}
