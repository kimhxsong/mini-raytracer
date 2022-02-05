/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:54:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/03 17:44:42 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

char	*ft_strjoinnl(char *str1, char *str2)
{
	char	*join;
	char	*temp;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (ft_strdupnl(str2));
	if (str1 && !str2)
		return (ft_strdupnl(str1));
	join = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 2) \
			* sizeof(char));
	if (!join)
		return (NULL);
	temp = join;
	while (*str1)
		*temp++ = *str1++;
	while (*str2)
		*temp++ = *str2++;
	*temp++ = '\n';
	*temp = '\0';
	return (join);
}
