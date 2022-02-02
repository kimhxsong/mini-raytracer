/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:21:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 12:46:04 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isvecform(char *str)
{
	char	*dup;
	char	*token;
	int		count;

	dup = ft_strdup(str);
	count = 3;
	token = ft_strtok(dup, ",");
	while (count > 0 && token)
	{
		if (!ft_isfloatform(token))
			break ;
		--count;
		token = ft_strtok(NULL, ",");
	}
	free(dup);
	if (!count && !token)
		return (1);
	return (0);
}

int	ft_isfloatform(char *str)
{
	str += ft_issign(*str);
	while (ft_isdigit(*str))
		++str;
	str += *str == '.';
	while (ft_isdigit(*str))
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
	while (ft_isdigit(*str) && maxlen-- > 0)
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

	dup = ft_strdup(str);
	count = 3;
	token = ft_strtok(dup, ",\n");
	while (count > 0 && token)
	{
		if (!ft_isintform(token))
			break ;
		--count;
		token = ft_strtok(NULL, ",\n");
	}
	free(dup);
	if (!count && !token)
		return (1);
	return (0);
}

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}
