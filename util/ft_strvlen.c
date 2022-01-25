/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:41:26 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 04:29:45 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

size_t  ft_strvlen(char **strv)
{
	size_t	strc;

	strc = 0;
	while (strv[strc])
		++strc;
	return (strc);
}
