/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 04:30:57 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_color ft_strtocolor(char *str)
{
	t_color	color;

	color.t = 0;
	color.r = ft_atof(ft_strtok(str, ",")) / 255;
	color.g = ft_atof(ft_strtok(NULL, ",")) / 255;
	color.b = ft_atof(ft_strtok(NULL, ",")) / 255;
	return (color);
}
