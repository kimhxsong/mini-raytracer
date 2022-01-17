#include "minirt.h"

int		in_shadow(t_obj *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color	vec_mult_c(t_color col1, double t)
{
	t_color color;

	color.t = col1.t * t;
	color.r = col1.r * t;
	color.g = col1.g * t;
	color.b = col1.b * t;
	return (color);
}

t_color	vec_plus_c(t_color col1, t_color col2)
{
	t_color color;

	color.t = col1.t + col2.t;
	color.r = col1.r + col2.r;
	color.g = col1.g + col2.g;
	color.b = col1.b + col2.b;
	return (color);
}

t_color		vec_min(t_color col1, t_color col2)
{
	col1.t = 0;
	if (col1.r > col2.r)
		col1.r = col2.r;
	if (col1.g > col2.g)
		col1.g = col2.g;
	if (col1.b > col2.b)
		col1.b = col2.b;
	return (col1);
}

t_color		vec_multc(t_color c1, t_color c2)
{
	c1.t *= c2.t;
	c1.r *= c2.r;
	c1.g *= c2.g;
	c1.b *= c2.b;
	return (c1);
}


// vec3	result = (ambient + diffuse + specular) * objectColor;
t_color	phong_lighting(t_data *data)
{
	t_color	light_color;
	t_light	light;			// 그림자
	double		light_len;
	t_ray		light_ray;
	t_vec		light_dir;
	t_ambient	al;			// ambient
	double		ka;
	t_color	ambient;
	double		kd;				// diffuse
	t_color	diffuse;
	double		brightness;		// 밝기


	light_color = color(0, 0, 0, 0);	// default로 설정
	light = data->light;
	// 그림자 계산: light_ray(교점->빛(교점:법벡 고려)), light_len: 빛과 교점 사이의 거리에서 중간에 물체가 있나 확인 
	light_dir = vec_minus(light.spot, data->rec.p);	// 교점->빛
	light_len = vec_cal_len(light_dir);	// 교점->빛의 길이
	light_ray = ray(vec_plus(data->rec.p, vec_mult(data->rec.normal, EPSILON)), light_dir);
	if (in_shadow(data->first_obj, light_ray, light_len))
		return(color(0, 0, 0, 0));
	light_dir = vec_cal_unit(light_dir);		// 단위 벡터
	al = data->ambient;
	ka = al.ratio;
	ambient = vec_mult_c(al.color, ka); // color(1,1,1) * ka
	// diffuse: 내적 이용
	kd = fmax(vec_dot(data->rec.normal, light_dir), 0.0);
	diffuse = vec_mult_c(al.color, kd); // color(1, 1, 1) * kd;
	// brightness: 
	brightness = light.ratio * LUMEN;
	light_color = vec_mult_c(vec_plus_c(ambient, diffuse), brightness);
	return (vec_min(vec_multc(light_color, data->rec.color), color(0, 255, 255, 255)));
}
