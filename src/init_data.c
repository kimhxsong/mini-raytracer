/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:19:59 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/12 17:03:13 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("mlx_init");
		exit(EXIT_FAILURE);
	}
}

static void	init_win(t_data *data)
{
	data->win.width = 1920;
	data->win.height = 1080;
	data->win.ptr = mlx_new_window(data->mlx_ptr, data->win.width, \
		data->win.height, "m!n!RT");
	if (!data->win.ptr)
	{
		perror("mlx_new_window");
		exit(EXIT_FAILURE);
	}
}

static void	init_img(t_data *data)
{
	data->img.ptr = \
		mlx_new_image(data->mlx_ptr, data->win.width, data->win.height);
	if (!data->img.ptr)
	{
		perror("mlx_new_image");
		mlx_destroy_window(data->mlx_ptr, data->win.ptr);
		exit(EXIT_FAILURE);
	}
	data->img.addr = mlx_get_data_addr(\
		data->img.ptr, &data->img.bpp, &data->img.width, &data->img.endian);
	if (!data->img.addr)
	{
		perror("mlx_get_data_addr");
		mlx_destroy_window(data->mlx_ptr, data->win.ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
		exit(EXIT_FAILURE);
	}
}

void	init_data(char *argv[], t_data *data)
{	
	memset(data, 0, sizeof(t_data));
	init_mlx(data);
	init_win(data);
	init_img(data);
	parse(open(argv[1], O_RDONLY), data);
	init_scene(data);
}
