/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:11:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 23:05:06 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_ray(t_ray *ray)
{
	ray->basis_k = vec_cal_unit(vec_mult(ray->dir, -1));
	ray->basis_i = vec_cal_unit(vec_cross(ray->up, ray->basis_k));
	ray->basis_j = vec_cross(ray->basis_k, ray->basis_i);
}

static void	alloc_view(t_cam *cam, double width, double height)
{
	int	i;

	cam->view.matrix = (t_vec **)malloc(height * sizeof(t_vec *));
	i = -1;
	while (++i < height)
		cam->view.matrix[i] = (t_vec *)malloc(width * sizeof(t_vec));
}

static void	init_view(t_cam *cam, double width, double height)
{
	const double	pi = acos(-1);
	t_vec			left_top;
	t_vec			center;
	int				i;
	int				j;

	cam->view.width = 2 * cam->ray.focal_len * tan(0.5 * pi * cam->ray.fov / 360);
	cam->view.height = cam->view.width * height / width;
	center = vec_minus(vec_mult(cam->ray.basis_k, cam->ray.focal_len), cam->ray.origin);
	left_top = vec_minus(center, \
		vec_plus(vec_mult(cam->ray.basis_i, cam->view.width * 0.5), \
		vec_mult(cam->ray.basis_j, cam->view.height * -0.5)));
	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			cam->view.matrix[j][i] = vec_plus(vec_plus(left_top, \
				vec_mult(cam->ray.basis_i, i * cam->view.width / width)), \
				vec_mult(cam->ray.basis_j, -j * cam->view.height / height));
		}
	}
}

void	init_cam(t_cam *cam, double width, double height)
{
	init_ray(&cam->ray);
	alloc_view(cam, width, height);
	init_view(cam, width, height);
}
