/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:51:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/12 11:34:00 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ft_strvfree(char *strv[])
{
	int i;

	i = -1;
	while (strv[++i])
	{
		free(strv[i]);
		strv[i] = NULL;
	}
	free(strv[i]);
	strv[i] = NULL;
	free(strv);
}