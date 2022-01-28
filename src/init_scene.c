/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:11:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 08:44:55 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cleanup(t_data *data)
{
	t_obj	*curr;
	void	*del;
	int		i;

	perror("malloc");
	mlx_destroy_window(data->mlx_ptr, data->win.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	curr = data->first_obj;
	while (curr)
	{
		free(curr->info);
		del = curr;
		curr = curr->next;
		free(del);
	}
	if (data->scene.view.matrix)
	{
		i = -1;
		while (++i < data->win.height)
			free(data->scene.view.matrix[i]);
	}
	free(data->scene.view.matrix);
	exit(1);
}

static void	init_cam(t_cam *cam)
{
	cam->focal_len = 1.f;
	if (cam->dir.j == -1 || cam->dir.j == 1)
	{
		cam->up.i = -1.f;
		cam->up.j = 0.f;
		cam->up.k = 0.f;
	}
	else
	{
		cam->up.i = 0.f;
		cam->up.j = 1.f;
		cam->up.k = 0.f;
	}
	// if (cam->dir.i == 0 && cam->dir.k == 0)
	// 	cam->dir.k = 0.00001;
	// cam->up.i = 0.f;
	// cam->up.j = 1.f;
	// cam->up.k = 0.f;
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
		cleanup(data);
	memset(data->scene.view.matrix, 0, data->win.height * sizeof(t_vec));
	i = -1;
	while (++i < data->win.height)
	{
		data->scene.view.matrix[i] = (t_vec *)malloc(data->win.width \
			* sizeof(t_vec));
		if (!data->scene.view.matrix[i])
			cleanup(data);
	}
	return (0);
}

static void	init_view(t_scene *scene, double width, double height)
{
	const double	pi = acos(-1);
	t_vec			left_top;
	t_vec			center;
	int				i;
	int				j;

	scene->view.width = 2 * scene->cam.focal_len \
		* tan(0.5 * pi * scene->cam.fov / 180);
	scene->view.height = scene->view.width * height / width;
	center = vec_plus(vec_mult(scene->cam.basis_k, -scene->cam.focal_len), \
		scene->cam.origin);
	left_top = vec_minus(center, \
		vec_plus(vec_mult(scene->cam.basis_i, scene->view.width * 0.5), \
		vec_mult(scene->cam.basis_j, scene->view.height * -0.5)));

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			scene->view.matrix[j][i] = vec_plus(vec_plus(left_top, \
				vec_mult(scene->cam.basis_i, i * scene->view.width / width)), \
				vec_mult(scene->cam.basis_j, -j * scene->view.height / height));
		}
	}
}

void	init_scene(t_data *data)
{
	init_cam(&data->scene.cam);
	alloc_view(data);
	init_view(&data->scene, data->win.width, data->win.height);
}
