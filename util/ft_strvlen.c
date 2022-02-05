/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:41:26 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:00:58 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

size_t	ft_strvlen(char **strv)
{
	size_t	strc;

	strc = 0;
	while (strv[strc])
		++strc;
	return (strc);
}
