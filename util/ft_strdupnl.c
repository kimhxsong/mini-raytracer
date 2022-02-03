/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:54:23 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 05:44:37 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

char	*ft_strdupnl(char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	new = (char *)malloc((len + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		++i;
	}
	new[i++] = '\n';
	new[i] = '\0';
	return (new);
}
