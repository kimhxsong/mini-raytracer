/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:11:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 20:15:19 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_ray(t_ray *ray)
{
	ray->basis_k = vec_cal_unit(vec_mult(ray->dir, -1));
	ray->basis_i = vec_cal_unit(vec_cross(ray->up, ray->basis_k));
	ray->basis_j = vec_cross(ray->basis_i, ray->basis_k);
}

static void	alloc_view(t_cam *cam, double width, double height)
{
	int	i;

	cam->view.matrix = (t_vec **)malloc(height * sizeof(t_vec *));
	i = -1;
	while (++i < width)
		cam->view.matrix[i] = (t_vec *)malloc(width * sizeof(t_vec));
}

static void	init_view(t_cam *cam, double width, double height)
{
	const double	pi = acos(-1);
    t_vec			left_bottom;
    t_vec   		center;
    int     		i;
    int     		j;

	cam->view.width =  cam->ray.focal_len * 2 * tan(2 * pi / (cam->ray.fov));
	cam->view.height = cam->view.width * height / width;
    center = vec_minus(cam->ray.origin, vec_mult(cam->ray.basis_i, cam->ray.focal_len));
    left_bottom = vec_minus(vec_minus(center, \
        vec_mult(cam->ray.basis_j, cam->view.width / 2)),
        vec_mult(cam->ray.basis_k, cam->view.height / 2));
    i = -1;
    j = -1;
    while (++i < height)
    {
        while (++j < width)
        {
            cam->view.matrix[i][j] = vec_plus(vec_plus(left_bottom, \
                vec_mult(cam->ray.basis_i, i * cam->view.width / width)), \
                vec_mult(cam->ray.basis_j, j * cam->view.height / height));
        }
    }
}

void	init_cam(t_cam *cam, double width, double height)
{
	cam->ray.dir = (t_vec){0, 0, -1};
	cam->ray.origin = (t_vec){0, 0, 1};
	cam->ray.up = (t_vec){0, 1, 0};
	cam->ray.focal_len = 1;
	cam->ray.fov = 120;
	init_ray(&cam->ray);
	alloc_view(cam, width, height);
	init_view(cam, width, height);
}
