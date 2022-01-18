/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:21:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/18 11:51:09 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "parse.h"

int	ft_isvecform(char *str)
{
	char	*dup;
	char	*token;
	int		count;

	dup = strdup(str);
	count = 3;
	token = strtok(dup, ",");
	while (count > 0 && token)
	{
		if (!ft_isfloatform(token))
			break ;
		--count;
		token = strtok(NULL, ",");
	}
	free(dup);
	if (!count && !token)
		return (1);
	return (0);
}


int	ft_isfloatform(char *str)
{
	int	i;

	str += ft_issign(*str);
	while(isdigit(*str))
		++str;
	str += *str == '.';
	while (isdigit(*str))
		++str;
	if (!*str)
		return (1);
	return (0);
}

int	ft_isintform(char *str)
{
	int	maxlen;

	maxlen = 10;
	str += ft_issign(*str);
	while(isdigit(*str) && maxlen-- > 0)
		++str;
	if (!*str)
		return (1);
	return (0);
}

int	ft_iscolorform(char *str)
{
	char	*token;
	char	*dup;
	int		count;
	
	dup = strdup(str);
	count = 3;
	token = strtok(dup, ",\n");
	while (count > 0 && token)
	{
		if (!ft_isintform(token))
			break ;
		--count;
		token = strtok(NULL, ",\n");
	}
	free(dup);
	if (!count && !token)
		return (1);
	return (0);
}
