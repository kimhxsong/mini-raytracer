/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:17:19 by SSONG             #+#    #+#             */
/*   Updated: 2022/02/05 19:09:03 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * TODO: TEST
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	if (dst == NULL && src == NULL)
	{
		return (0);
	}
	len = ft_strlen(src);
	if (dst == NULL)
	{
		return (len);
	}
	while (*src != '\0' && dstsize > 1)
	{
		*dst = *src;
		++dst;
		++src;
		--dstsize;
	}
	*dst = '\0';
	return (len);
}
