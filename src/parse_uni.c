/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:22:27 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/11 17:44:08 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(t_data *data, char *strv[])
{
	data->ambient.ratio = atof(strv[1]);
	data->ambient.color.t = 0;
	data->ambient.color.r = atof(strtok(strv[2], ","));
	data->ambient.color.g = atof(strtok(NULL, ","));
	data->ambient.color.b = atof(strtok(NULL, ","));
}

void	parse_light(t_data *data, char *strv[])
{
	data->light.spot.i = atof(strtok(strv[1], ","));
	data->light.spot.j = atof(strtok(NULL, ","));
	data->light.spot.k = atof(strtok(NULL, ","));
	data->light.ratio = atof(strv[2]);
}

void	parse_camera(t_data *data, char *strv[])
{
	data->cam.ray.origin.i = atof(strtok(strv[1], ","));
	data->cam.ray.origin.j = atof(strtok(NULL, ","));
	data->cam.ray.origin.k = atof(strtok(NULL, ","));
	data->cam.ray.dir.i = atof(strtok(strv[2], ","));
	data->cam.ray.dir.j = atof(strtok(NULL, ","));
	data->cam.ray.dir.k = atof(strtok(NULL, ","));
	data->cam.ray.fov = atof(strv[3]);
}