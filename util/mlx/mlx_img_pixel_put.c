/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:13:18 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/16 17:05:43 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void    mlx_img_pixel_put(t_img *img, int color, int x, int y)
{
	char	*dest;

	dest = img->addr + (y * img->width + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}
