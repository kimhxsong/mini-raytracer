/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:00:47 by SSONG             #+#    #+#             */
/*   Updated: 2022/02/05 19:09:03 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * TODO: TEST
 */

char	*ft_strrchr(const char *s1, int ch)
{
	char	*s;

	s = (char *)s1 + ft_strlen(s1);
	while (*s != ch)
	{
		if (s == s1)
			return (NULL);
		--s;
	}
	return (s);
}
