/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:31:23 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/12 17:15:19 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cleanup(t_data *data)
{
	t_obj	*curr;
	void	*del;
	int		i;

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
	i = -1;
	while (++i < data->win.height)
		free(data->scene.view.matrix[i]);
	free(data->scene.view.matrix);
	printf("Exit\n");
	exit(0);
}

static int	mouse_event(t_data *data)
{
	cleanup(data);
	return (0);
}

static int	key_event(int keycode, t_data *data)
{
	if (keycode == ESC)
		cleanup(data);
	return (0);
}

void	listen_event(t_data *data)
{
	mlx_key_hook(data->win.ptr, key_event, data);
	mlx_hook(data->win.ptr, 17, 0, mouse_event, data);
	mlx_loop(data->mlx_ptr);
}
