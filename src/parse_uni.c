/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:22:27 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/13 15:58:48 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	handle_execption(t_data *data, char *strv[])
{
	t_obj	*curr;
	void	*del;
	int		i;

	if (*strv[0] == '\n')
		return ;
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
	ft_strvfree(strv);
	ft_error("More than once an uppercase identifier is declared");
}

void	parse_ambient(t_data *data, char *strv[])
{
	static int	count;

	if (count++)
		handle_execption(data, strv);
	data->ambient.ratio = atof(strv[1]);
	data->ambient.color.t = 0;
	data->ambient.color.r = atof(strtok(strv[2], ","));
	data->ambient.color.g = atof(strtok(NULL, ","));
	data->ambient.color.b = atof(strtok(NULL, ","));
}

void	parse_light(t_data *data, char *strv[])
{
	static int	count;

	if (count++)
		handle_execption(data, strv);
	data->light.spot.i = atof(strtok(strv[1], ","));
	data->light.spot.j = atof(strtok(NULL, ","));
	data->light.spot.k = atof(strtok(NULL, ","));
	data->light.ratio = atof(strv[2]);
}

void	parse_camera(t_data *data, char *strv[])
{
	static int	count;

	if (count++)
		handle_execption(data, strv);
	data->scene.cam.origin.i = atof(strtok(strv[1], ","));
	data->scene.cam.origin.j = atof(strtok(NULL, ","));
	data->scene.cam.origin.k = atof(strtok(NULL, ","));
	data->scene.cam.dir.i = atof(strtok(strv[2], ","));
	data->scene.cam.dir.j = atof(strtok(NULL, ","));
	data->scene.cam.dir.k = atof(strtok(NULL, ","));
	data->scene.cam.fov = atof(strv[3]);
}
