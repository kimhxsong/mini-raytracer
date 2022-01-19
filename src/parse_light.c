/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:38:51 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 15:49:43 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_light(t_light *light, char *strv[])
{
	int	isform;

	if (light->count++)
		ft_error("More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 3)
		ft_error("Invalid 'Light' description");
	isform = ft_isvecform(strv[1]) && ft_isfloatform(strv[2]);
	if (!isform)
		ft_error("Invalid 'Light' description");
}

static void	init_obj_light(t_light *light, char *strv[])
{
	light->spot = ft_strtovec(strv[1]);
	light->ratio = ft_atof(strv[2]);
	if (!ft_isinscope(light->ratio, 1.0f, 0.0f))
		ft_error("Invalid 'Light' ratio");
}

void	parse_light(t_data *data, char *strv[])
{
	validate_light(&data->light, strv);
	init_obj_light(&data->light, strv);
}
