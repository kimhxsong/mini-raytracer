/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:57:08 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:14:27 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	unsigned long long	val;
	int					sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		++str;
	}
	val = 0;
	while (*str >= '0' && *str <= '9')
	{
		val += val * 10 + *str - '0';
		++str;
	}
	return (sign * val);
}
