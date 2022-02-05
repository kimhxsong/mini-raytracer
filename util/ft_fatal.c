/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:13:01 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 05:52:46 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdio.h>

void	ft_fatal(const char *str)
{
	ft_dputendl(2, "Error");
	perror(str);
	exit(EXIT_FAILURE);
}
