/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtovec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:10 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 19:09:22 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_vec   ft_strtovec(char *str)
{
	t_vec	vec;

	vec.i  = atof(strtok(str, ","));
	vec.j  = atof(strtok(NULL, ","));
	vec.k  = atof(strtok(NULL, ","));
    return (vec);
}
