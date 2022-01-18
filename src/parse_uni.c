/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:22:27 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/18 12:10:22 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(t_data *data, char *strv[])
{
	static int	count;
	int			isform;

	if (count++)
		ft_error("More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 3)
		ft_error("Invalid 'Ambient light' description\n");
	isform = ft_isfloatform(strv[1]) && ft_iscolorform(strv[2]);
	if (!isform)
		ft_error("Invalid 'Ambient light' description\n");
	data->ambient.ratio = ft_atof(strv[1]);
	data->ambient.color = ft_strtocolor(strv[2]);
}

void	parse_camera(t_data *data, char *strv[])
{
	static int	count;
	int			isform;

	if (count++)
		ft_error("More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 4)
		ft_error("Invalid 'Camera' description\n");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_isfloatform(strv[3]);
	if (!isform)
		ft_error("Invalid 'Camera' description\n");
	data->scene.cam.origin = ft_strtovec(strv[1]);
	data->scene.cam.dir = ft_strtovec(strv[2]);
	data->scene.cam.fov = ft_atof(strv[3]);
	data->scene.cam.up.j = 1.0f;
	data->scene.cam.focal_len = FOCAL_LEN;
}

void	parse_light(t_data *data, char *strv[])
{
	static int	count;
	int			isform;

	if (count++)
		ft_error("More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 3)
		ft_error("Invalid 'Light' description\n");
	isform = ft_isvecform(strv[1]) && ft_isfloatform(strv[2]);
	if (!isform)
		ft_error("Invalid 'Light' description\n");
	data->light.spot = ft_strtovec(strv[1]);
	data->light.ratio = ft_atof(strv[2]);
}

