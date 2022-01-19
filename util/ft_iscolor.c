/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:20:52 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 15:31:39 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	ft_iscolor(t_color color)
{
	return (ft_isinscope(color.r, 1.0, 0.0) && ft_isinscope(color.g, 1.0, 0.0) 
		&& ft_isinscope(color.b, 1.0, 0.0));
}
