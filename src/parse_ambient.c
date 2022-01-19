/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:17 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 15:49:11 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_ambient(t_ambient *ambient, char *strv[])
{
	int	isform;

	if (ambient->count++)
		ft_error("More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 3)
		ft_error("Invalid 'Ambient light' description");
	isform = ft_isfloatform(strv[1]) && ft_iscolorform(strv[2]);
	if (!isform)
		ft_error("Invalid 'Ambient light' description");
}

static void	init_ambient(t_ambient *ambient, char *strv[])
{
	ambient->ratio = ft_atof(strv[1]);
	if (!ft_isinscope(ambient->ratio, 1.0f, 0.0f))
		ft_error("Invalid 'Ambient light' ratio");
	ambient->color = ft_strtocolor(strv[2]);
	if (!ft_iscolor(ambient->color))
		ft_error("Invaild 'Ambient light' RGB");
}

void	parse_ambient(t_data *data, char *strv[])
{
	validate_ambient(&data->ambient, strv);
	init_ambient(&data->ambient, strv);
}