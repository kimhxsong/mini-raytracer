#include "minirt.h"

int hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec oc;
	double a;
	double half_b;
	double c;
	double	discriminant;
	double	sqrtd;
	double	root;
	double radius2;

	radius2 = sp->radius * sp->radius;
	oc = vec_minus(ray->orig, sp->center);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < 0)
	{
		root = (-half_b + sqrtd) / a;
		if (root < 0)
			return (FALSE);
	}
	return (TRUE);
}

