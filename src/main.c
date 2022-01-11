/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:35:48 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/11 18:02:20 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_scene(t_data *data)
{
	/*
	yookim
	*/
	mlx_put_image_to_window(data->mlx_ptr, data->win.ptr, data->img.ptr, \
		data->win.width, data->win.height);
}

static void	validate_args(int argc, char *argv[])
{
	char	*ext;

	if (argc != 2)
		ft_error("There are no or more than one arguments");
	ext = strrchr(argv[1], '.');
	if (!ext || strcmp(ext, ".rt"))
		ft_error("The extension of the argument is not *.rt");
}

int main(int argc, char *argv[])
{
	t_data	data;
	
	validate_args(argc, argv);
	init_data(argv, &data);
	draw_scene(&data);
	listen_event(&data);
	return (0);
}
