/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:47:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:00:03 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static void	ft_atof_integer(double *integer, char **str)
{
	double	sign;

	sign = 1;
	*str += ft_strspn(*str, " \t");
	if (**str == '-')
		sign = -1;
	*str += ft_issign(**str);
	while (**str && **str != '.' && ft_isdigit(**str))
	{
		*integer *= 10;
		*integer += **str - '0';
		++*str;
	}
	*integer = sign * *integer;
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

	integer = 0;
	decimal = 0;
	ft_atof_integer(&integer, &str);
	str += (*str == '.');
	if (!*str)
		return (integer);
	ft_atof_decimal(&decimal, str);
	return (integer + decimal);
}
