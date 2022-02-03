/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:11:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/03 17:52:39 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_cam(t_cam *cam)
{
	cam->up.j = 1.0f;
	cam->focal_len = FOCAL_LEN;
	if (cam->dir.j == 1.f || cam->dir.j == -1.f)
	{
		cam->up.j = 0.f;
		cam->up.k = 1.f;
	}
	cam->basis_k = vec_cal_unit(vec_mult(cam->dir, -1));
	cam->basis_i = vec_cal_unit(vec_cross(cam->up, cam->basis_k));
	cam->basis_j = vec_cross(cam->basis_k, cam->basis_i);
}

static int	alloc_view(t_data *data)
{
	int	i;

	data->scene.view.matrix = (t_vec **)malloc(data->win.height \
		* sizeof(t_vec));
	if (!data->scene.view.matrix)
		return (0);
	memset(data->scene.view.matrix, 0, data->win.height * sizeof(t_vec));
	i = -1;
	while (++i < data->win.height)
	{
		data->scene.view.matrix[i] = (t_vec *)malloc(data->win.width \
			* sizeof(t_vec));
		if (!data->scene.view.matrix[i])
			return (0);
	}
	return (1);
}

static void	calculate_view_matrix(t_scene *scene, t_vec *left_top, \
									double width, double height)
{
	int	i;
	int	j;

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			scene->view.matrix[j][i] = vec_minus(vec_plus(vec_plus(*left_top, \
				vec_mult(scene->cam.basis_i, i * scene->view.width / width)), \
				vec_mult(scene->cam.basis_j, -j * scene->view.height / height)),
					scene->cam.origin);
		}
	}
}

static void	init_view(t_scene *scene, double width, double height)
{
	const double	pi = acos(-1);
	t_vec			left_top;
	t_vec			center;

	scene->view.width = 2 * scene->cam.focal_len \
		* tan(0.5 * pi * scene->cam.fov / 180);
	scene->view.height = scene->view.width * height / width;
	center = vec_plus(vec_mult(scene->cam.basis_k, -scene->cam.focal_len), \
		scene->cam.origin);
	left_top = vec_minus(center, \
		vec_plus(vec_mult(scene->cam.basis_i, scene->view.width * 0.5), \
		vec_mult(scene->cam.basis_j, scene->view.height * -0.5)));
	calculate_view_matrix(scene, &left_top, width, height);
}

void	init_scene(t_data *data)
{
	init_cam(&data->scene.cam);
	if (!alloc_view(data))
	{
		perror("alloc_view: malloc");
		exit(1);
	}
	init_view(&data->scene, data->win.width, data->win.height);
}
