/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:47:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 16:05:16 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

double	ft_atof(char *str)
{
	double	integer;
	double	decimal;
	double	sign;

	integer = 0.0f;
	decimal = 0.0f;
	sign = 1;
	while (isspace((int)*str))
		++str;
	if (*str == '-')
		sign = -1;
	str += *str == '+' || *str == '-';
	while (*str && *str != '.' && (*str >= '0' && *str <= '9'))
	{
		integer *= 10;
		integer += *str - '0';
		++str;
	}
	if (*str != '.' || !*str)
		return (sign * integer);
	str++;
	while (*str && (*str >= '0' && *str <= '9'))
		++str;
	while (*--str && *str != '.')
	{
		decimal += *str - '0';
		decimal *= 0.1;
	}
	return (sign * integer + decimal);
}
