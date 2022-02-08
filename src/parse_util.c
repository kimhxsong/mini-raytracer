/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:21:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/08 17:59:04 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minirt.h"

//TODO: Implement strsep then, Replace with ft_strsep
int	ft_isvecform(char *str)
{
	char	*strp;
	char	*tofree;
	char	*token;
	int		count;

	strp = ft_strdup(str);
	if (!strp)
		ft_fatal("malloc");
	tofree = strp;
	count = 3;
	while (count > 0)
	{
		token = strsep(&strp, ",");
		if (token == NULL)
			break ;
		if (!ft_isfloatform(token))
			break ;
	}
	free(tofree);
	return (count == 0);
}

int	ft_isfloatform(char *str)
{
	if (ft_strlen(str) > 15)
		return (0);
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
	char	*strp;
	char	*tofree;
	char	*token;
	int		count;

	strp = ft_strdup(str);
	if (!strp)
		ft_fatal("malloc");
	tofree = strp;
	count = 3;
	while (count > 0)
	{
		token = strsep(&strp, ",");
		if (token == NULL)
			break ;
		if (!ft_isintform(token))
			break ;
	}
	free(tofree);
	return (count == 0);
}

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}
