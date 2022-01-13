#ifndef HIT_H
# define HIT_H
# include "vec.h"

typedef struct s_ray
{
	t_point	orig; // 정점.시작점
	t_vec	dir;    // 방향 벡터(단위 벡터O)
} t_ray;

int hit_sphere(t_sphere *sp, t_ray *ray);

#endif
