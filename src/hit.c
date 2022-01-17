#include "minirt.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vec_mult(rec->normal, -1);
}

int hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec co;
	double a;
	double half_b;
	double c;
	double	discriminant;
	double	sqrtd;
	double	root;
	double radius2;

	radius2 = sp->radius * sp->radius;
	co = vec_minus(ray->orig, sp->center);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(co, ray->dir);
	c = vec_dot(co, co) - radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	// rec->normal = vec_mult(vec_minus(rec->p, sp->center), 1 / sp->radius);
	rec->normal = vec_cal_unit(vec_minus(rec->p, sp->center));
	set_face_normal(ray, rec);
	return (TRUE);
}

int hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec	h_unit;
	t_vec	h;
	t_vec	co;
	double	discriminant;
	double	a;
	double	half_b;
	double	c;
	double	sqrt_d;
	double	root;
	t_point p;
	double	h_range;
	double	radius2;

	cy->radius = cy->diameter / 2;
	radius2 = cy->radius * cy->radius;
	h_unit = vec_cal_unit(cy->normal);
	h = vec_plus(cy->center, vec_mult(h_unit, cy->height));
	co = vec_minus(ray->orig, cy->center);
	a = vec_dot(ray->dir, ray->dir) - pow(vec_dot(ray->dir, h_unit), 2);
	half_b = vec_dot(ray->dir, co) - (vec_dot(ray->dir, h_unit) * vec_dot(co, h_unit));
	c = vec_dot(co, co) - pow(vec_dot(co, h_unit), 2) - radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrt_d = sqrt(discriminant);
	root = (-half_b - sqrt_d) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrt_d ) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
		p = ray_at(ray, root);
		h_range = vec_dot(vec_minus(p, cy->center), h_unit);
		if (h_range < 0 || h_range > cy->height)
			return (FALSE);
	}
	else
	{
		p = ray_at(ray, root);
		h_range = vec_dot(vec_minus(p, cy->center), h_unit);
		if (h_range < 0 || h_range > cy->height)
		{
			root = (-half_b + sqrt_d) / a;
			if (root < rec->tmin || rec->tmax < root)
				return (FALSE);
			p = ray_at(ray, root);
			h_range = vec_dot(vec_minus(p, cy->center), h_unit);
			if (h_range < 0 || h_range > cy->height)
				return (FALSE);
		}
	}
	rec->t = root;
	rec->p = p;
	// rec->normal = vec_mult(vec_minus(p, vec_plus(cy->center, vec_mult(h_unit, h_range))), 1 / cy->radius);
	rec->normal = vec_cal_unit(vec_minus(p, vec_plus(cy->center, vec_mult(h_unit, h_range))));
	set_face_normal(ray, rec);
	return (TRUE);
}

int		hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	t_vec oc;
	double	dot_two; // 내적2
	double	root;

	oc = vec_minus(pl->center, ray->orig);
	dot_two = vec_dot(ray->dir, pl->normal);
	if (fabs(dot_two) <= EPSILON)
		return (FALSE);
	root = vec_dot(oc, pl->normal) / dot_two;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_cal_unit(pl->normal);
	set_face_normal(ray, rec);
	return (TRUE);
}

int		hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	int		hit_result;

	hit_result = FALSE;
	if (obj->type == TYPE_SP)
		hit_result = hit_sphere((t_sphere *)obj->info, ray, rec);
	else if (obj->type == TYPE_PL)
		hit_result = hit_plane((t_plane *)obj->info, ray, rec);
	else if (obj->type == TYPE_CY)
		hit_result = hit_cylinder((t_cylinder *)obj->info, ray, rec);
	return (hit_result);
}

int		hit(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	int				hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (obj)
	{
		if (hit_obj(obj, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.color = obj->color;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}
