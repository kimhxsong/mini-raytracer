/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 02:07:54 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_color ft_strtocolor(char *str)
{
	t_color	color;

	color.t = 0;
	color.r = atof(strtok(str, ",")) / 255;
	color.g = atof(strtok(NULL, ",")) / 255;
	color.b = atof(strtok(NULL, ",")) / 255;
    return (color);
}
