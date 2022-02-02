/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:13:01 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:24:28 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdio.h>

void	ft_fatal(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
