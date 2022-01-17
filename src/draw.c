#include "minirt.h"

t_ray		ray(t_point orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_cal_unit(dir);
	return (ray);
}

t_ray ray_view(t_scene *scene, int i, int j)
{
    t_ray ray;

    ray.orig = scene->cam.origin;
	ray.dir = scene->view.matrix[j][i];
    return (ray);
}


t_point ray_at(t_ray *ray, double t)
{
    t_point at;
	// p(t) = orig + t * dir;
    at = vec_plus(ray->orig, vec_mult(ray->dir, t));
    return (at);
}

t_color		color(double t, double r, double g, double b)
{
	t_color color;

	color.t = t;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color		ray_color(t_data *data)
{
	data->rec = record_init();
	if (hit(data->first_obj, &data->ray, &data->rec))
		return (phong_lighting(data));
		// return (data->first_obj->color); // phong_lighting의 문제?
		// return(data->rec.color); // Yes
	else
		// return (color(0, 0, 0, 0));
		return(color(0, 255, 255, 0)); // 임시 배경
}

void	draw_scene(t_data *data)
{
	t_ray	ray;
	int		i;
	int		j;
	t_scene  scene;
	t_color pixel_color;

	scene = data->scene;
	j = -1;
	while (++j < WIN_SIZE_Y)
	{
		i = -1;
		while (++i < WIN_SIZE_X)
		{
			data->ray = ray_view(&scene, i, j);
			pixel_color = ray_color(data);
			mlx_img_pixel_put(&data->img, convert_rgb(pixel_color), i, j);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win.ptr, data->img.ptr, 0, 0);
}
