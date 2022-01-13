#include "minirt.h"

t_ray ray_view(t_scene *scene, int i, int j)
{
    t_ray ray;

    ray.orig = scene->cam.origin;
	ray.dir = scene->view.matrix[j][i];
    return (ray);
}

t_color *ray_color(t_ray *ray, t_obj *obj)
{
    if (obj->type == TYPE_SP)
    {
        if (hit_sphere((t_sphere *)obj->info, ray))
            return (&obj->color);
    }
    return (0);
}

void	draw_scene(t_data *data)
{
	t_ray	ray;
	int		i;
	int		j;
	t_scene  scene;
	t_color	*pixel_color;
	t_color black;

	memset(&black, 0, sizeof(t_color));
	scene = data->scene;
	j = -1;
	while (++j < WIN_SIZE_Y)
	{
		i = -1;
		while (++i < WIN_SIZE_X)
		{
			ray = ray_view(&scene, i, j);
			pixel_color = ray_color(&ray, data->first_obj);
			if (!pixel_color)
				pixel_color = &black;
			mlx_img_pixel_put(&data->img, pixel_color, i, j);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win.ptr, data->img.ptr, 0, 0);
}
