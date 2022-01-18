#ifndef HIT_H
# define HIT_H
# include "vec.h"

int		hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
int hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
int hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec);
t_point ray_at(t_ray *ray, double t);
t_color	phong_lighting(t_data *data);
#endif
