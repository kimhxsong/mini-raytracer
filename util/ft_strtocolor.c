/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 19:09:41 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_color ft_strtocolor(char *str)
{
	t_color	color;

	color.t = 0;
	color.r = atof(strtok(str, ","));
	color.g = atof(strtok(NULL, ","));
	color.b = atof(strtok(NULL, ","));
    return (color);
}
