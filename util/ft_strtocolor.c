/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 15:59:59 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_color ft_strtocolor(char *str)
{
	t_color	color;

	color.t = 0;
	color.r = (double)ft_atoi(ft_strtok(str, ",")) / 255;
	color.g = (double)ft_atoi(ft_strtok(NULL, ",")) / 255;
	color.b = (double)ft_atoi(ft_strtok(NULL, ",")) / 255;
	return (color);
}
