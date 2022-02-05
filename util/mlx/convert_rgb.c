/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:19:22 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:03:43 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	convert_rgb(t_color color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)(color.t * 255.999);
	r = (int)(color.r * 255.999);
	g = (int)(color.g * 255.999);
	b = (int)(color.b * 255.999);
	return (t << 24 | r << 16 | g << 8 | b);
}
