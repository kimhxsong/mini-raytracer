/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:34:45 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/05 19:38:40 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ft_error(char *str)
{
	ft_dputendl(2, "Error");
	ft_dputendl(2, str);
	exit(EXIT_FAILURE);
}
