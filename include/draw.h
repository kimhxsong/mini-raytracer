#ifndef DRAW_H
# define DRAW_H
# include "minirt.h"


void	draw_scene(t_data *data);
t_color		color(double t, double r, double g, double b);
t_ray		ray(t_point orig, t_vec dir);
#endif
