/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:19:59 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/18 12:16:33 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_fatal("mlx_init");
}

static void	init_win(t_data *data)
{
	data->win.width = 1920;
	data->win.height = 1080;
	data->win.ptr = mlx_new_window(data->mlx_ptr, data->win.width, \
		data->win.height, "m!n!RT");
	if (!data->win.ptr)
		ft_fatal("mlx_new_window");
}

static void	init_img(t_data *data)
{
	data->img.ptr = \
		mlx_new_image(data->mlx_ptr, data->win.width, data->win.height);
	if (!data->img.ptr)
		ft_fatal("mlx_new_image");
	data->img.addr = mlx_get_data_addr(\
		data->img.ptr, &data->img.bpp, &data->img.width, &data->img.endian);
	if (!data->img.addr)
		ft_fatal("mlx_get_data_addr");
}

void	init_data(char *argv[], t_data *data)
{	
	memset(data, 0, sizeof(t_data));
	parse(open(argv[1], O_RDONLY), data);
	init_mlx(data);
	init_win(data);
	init_img(data);
	init_scene(data);
}
