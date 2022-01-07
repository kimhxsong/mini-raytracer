/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:31:23 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/07 15:55:06 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static int mouse_event(t_data *data)
{
    printf("red cross\n");
    exit(0);
    // cleanup()...
    // mlx_destroy_image(data.mlx_ptr, data.img.ptr);
    // mlx_destroy_window(data.mlx_ptr, data.win.ptr);
    // etc..
    return (0);
}

static int key_event(int keycode, t_data *data)
{
    printf("%d\n", keycode);
    exit(0);
    // cleanup()...
    // mlx_destroy_image(data.mlx_ptr, data.img.ptr);
    // mlx_destroy_window(data.mlx_ptr, data.win.ptr);
    // etc..
    return (0);
}

void    listen_event(t_data *data)
{
    mlx_key_hook(data->win.ptr, key_event, data);
    mlx_hook(data->win.ptr, 17, 0, mouse_event, data);
    mlx_loop(data->mlx_ptr);
}
