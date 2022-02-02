/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:51:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:02:02 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ft_strvfree(char *strv[])
{
	int	i;

	if (!strv)
		return ;
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
