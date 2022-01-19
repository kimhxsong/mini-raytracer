/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 15:49:14 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_camera(t_scene *scene, char *strv[])
{
	int	isform;

	if (scene->count++)
		ft_error("More than once an uppercase identifier is declared");
	if (ft_strvlen(strv) != 4)
		ft_error("Invalid 'Camera' description\n");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_isfloatform(strv[3]);
	if (!isform)
		ft_error("Invalid 'Camera' description\n");
}

static void	init_camera(t_cam *cam, char *strv[])
{
	cam->origin = ft_strtovec(strv[1]);
	cam->dir = ft_strtovec(strv[2]);
	if (!ft_isunitvec(cam->dir))
		ft_error("Invalid 'Camera' 3d normalized orientation vector");
	cam->fov = ft_atof(strv[3]);
	if (!ft_isinscope(cam->fov, 180, 0))
		ft_error("Invalid 'Camera' FOV");
	cam->up.j = 1.0f;
	cam->focal_len = FOCAL_LEN;
}

void	parse_camera(t_data *data, char *strv[])
{
	validate_camera(&data->scene, strv);
	init_camera(&data->scene.cam, strv);
}
