/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:13:18 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 05:08:59 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	 mlx_img_pixel_put(t_img *img, int color, int x, int y)
{
	char	*dest;

	dest = img->addr + (y * img->width + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}
