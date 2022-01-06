/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:35:48 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 20:27:09 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(void)
{
    t_data  data;
    
    //setup_mlx; test-assignment
    data.win.width = 1920;
    data.win.height = 1080;
    // data.mlx_ptr = mlx_init();
    // data.win.ptr = mlx_new_window(data.mlx_ptr, data.win.width, data.win.height, "m!n!RT");
    // mlx_img_init(data.mlx_ptr, &data.win, &data.img);

    //setup ray; test assignment
    data.cam.ray.dir = (t_vec){0, 0, -1};
	data.cam.ray.origin = (t_vec){0, 0, 1};
	data.cam.ray.up = (t_vec){0, 1, 0};
	data.cam.ray.focal_len = 1.f;
	data.cam.ray.fov = 120.f;

    init_cam(&data.cam, data.win.width, data.win.height);
    //break point; lldb check

    // mlx_put_image_to_window(data.mlx_ptr, data.win.ptr, data.img.ptr, data.win.width, data.win.height);
    //mlx_loop(data.mlx_ptr);
    // mlx_destroy_image(data.mlx_ptr, data.img.ptr);
    // mlx_destroy_window(data.mlx_ptr, data.win.ptr);
    return (0);
}
