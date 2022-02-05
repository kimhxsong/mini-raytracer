/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:17 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 06:05:40 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_ambient(t_ambient *ambient, char *strv[])
{
	int	isform;

	if (ambient->count++)
		ft_error("validate_ambient: More than once an uppercase identifier is \
			declared");
	if (ft_strvlen(strv) != 3)
		ft_error("validate_ambient: Invalid description");
	isform = ft_isfloatform(strv[1]) && ft_iscolorform(strv[2]);
	if (!isform)
		ft_error("validate_ambient: Invalid description");
}

static void	init_ambient(t_ambient *ambient, char *strv[])
{
	ambient->ratio = ft_atof(strv[1]);
	if (!ft_isinscope(ambient->ratio, 1.0f, 0.0f))
		ft_error("init_ambient: Invalid ratio");
	ambient->color = ft_strtocolor(strv[2]);
	if (!ft_iscolor(ambient->color))
		ft_error("init_ambient: Invaild RGB");
}

void	parse_ambient(t_data *data, char *strv[])
{
	validate_ambient(&data->ambient, strv);
	init_ambient(&data->ambient, strv);
}
