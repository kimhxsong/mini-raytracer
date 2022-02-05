/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:47:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 03:34:00 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static void	ft_atof_integer(double *integer, char **str)
{
	while (**str && **str != '.' && ft_isdigit(**str))
	{
		*integer *= 10;
		*integer += **str - '0';
		++*str;
	}
}

static void	ft_atof_decimal(double *decimal, char *str)
{
	while (*str && ft_isdigit(*str))
		++str;
	while (*--str && *str != '.')
	{
		*decimal += *str - '0';
		*decimal *= 0.1;
	}
}

double	ft_atof(char *str)
{
	double	integer;
	double	decimal;
	double	sign;
	double	ret;

	str += ft_strspn(str, " \t");
	sign = 1;
	if (*str == '-')
		sign = -1;
	str += ft_issign(*str);
	integer = 0;
	decimal = 0;
	ft_atof_integer(&integer, &str);
	str += (*str == '.');
	if (!*str)
		return (integer * sign);
	ft_atof_decimal(&decimal, str);
	ret = (integer + decimal) * sign;
	return ((integer + decimal) * sign);
}
