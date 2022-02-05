/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:36:04 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:13:07 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (!ft_strchr(charset, *p))
			break ;
		p++;
	}
	return (p - s);
}

size_t	ft_strcspn(const char *s, char *charset)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (ft_strchr(charset, *p))
			break ;
		p++;
	}
	return (p - s);
}

char	*ft_strpbrk(const char *s, const char *charset)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (ft_strchr(charset, *p))
			return (p);
		p++;
	}
	return (NULL);
}

char	*ft_strtok(const char *str, const char *sep)
{
	static char	*save;
	char		*tok;
	char		*brk;

	if (str)
		save = (char *)str;
	if (!save)
		return (NULL);
	tok = save + ft_strspn(save, sep);
	if (!*tok)
	{
		save = NULL;
		return (NULL);
	}
	brk = ft_strpbrk(tok, sep);
	if (brk)
	{
		*brk = '\0';
		save = ++brk;
	}
	else
		save = NULL;
	return (tok);
}
