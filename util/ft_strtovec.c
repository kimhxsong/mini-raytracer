/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtovec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:10 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 04:30:39 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_vec	ft_strtovec(char *str)
{
	t_vec	vec;

	vec.i = ft_atof(ft_strtok(str, ","));
	vec.j = ft_atof(ft_strtok(NULL, ","));
	vec.k = ft_atof(ft_strtok(NULL, ","));
	return (vec);
}
