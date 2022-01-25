/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:47:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 05:07:33 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static	void	_atof_integer(double *integer, char **str)
{
	double	sign;

	*str += ft_strspn(*str, " \t");
	sign = 1;
	if (**str == '-')
		sign = -1;

	*str += ft_issign(**str);
	while (**str && **str != '.' && ft_isdigit(**str))
	{
		*integer *= 10;
		*integer += **str - '0';
		++*str;
	}
	*integer *= sign;
}

static	void	_atof_decimal(double *decimal, char *str)
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

	integer = 0;
	decimal = 0;
	_atof_integer(&integer, &str);
	str += (*str == '.');
	_atof_decimal(&decimal, str);
	return (integer + decimal);
}
