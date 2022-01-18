/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:51:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/18 11:30:20 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ft_strvfree(char *strv[])
{
	int i;

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
