/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:19:22 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 10:32:55 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int		convert_rgb(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.r);
	g = (int)(color.g);
	b = (int)(color.b);
	return (0 << 24 | r << 16 | g << 8 | b);
}
