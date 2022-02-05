/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunitvec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:21:10 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:01:41 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#define MARGIN_OF_ERROR 0.1f

int	ft_isunitvec(t_vec vec)
{
	double	res;

	res = vec.i * vec.i + vec.j * vec.j + vec.k * vec.k;
	if (res < 1.f - MARGIN_OF_ERROR || res > 1.f + MARGIN_OF_ERROR)
		return (0);
	return (1);
}
