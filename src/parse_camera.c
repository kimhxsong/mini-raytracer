/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 06:04:42 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_camera(t_scene *scene, char *strv[])
{
	int	isform;

	if (scene->count++)
		ft_error("validate_camera: More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 4)
		ft_error("validate_camera: Invalid description\n");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_isfloatform(strv[3]);
	if (!isform)
		ft_error("validate_camera: Invalid description\n");
}

static void	init_camera(t_cam *cam, char *strv[])
{
	cam->origin = ft_strtovec(strv[1]);
	cam->dir = ft_strtovec(strv[2]);
	if (!ft_isunitvec(cam->dir))
		ft_error("init_camera: Invalid 3d normalized orientation vector");
	cam->fov = ft_atof(strv[3]);
	if (!ft_isinscope(cam->fov, 180, 0))
		ft_error("init_camera: Invalid FOV");
}

void	parse_camera(t_data *data, char *strv[])
{
	validate_camera(&data->scene, strv);
	init_camera(&data->scene.cam, strv);
}
