/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:44:44 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/05 18:50:27 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_light		t_light;
typedef struct s_ambient	t_ambient;
typedef struct s_obj		t_obj;
typedef struct s_cam		t_cam;
typedef struct s_view		t_view;
typedef struct s_scene		t_scene;
typedef struct s_hit_record	t_hit_record;
typedef struct s_data		t_data;
typedef struct s_ray		t_ray;

typedef struct s_parser {
	void	(*fn)(struct s_data *, char*[]);
}	t_parser;

enum e_type {
	TYPE_SP,
	TYPE_PL,
	TYPE_CY
};

enum e_spec {
	SPEC_A,
	SPEC_C,
	SPEC_L,
	SPEC_PL,
	SPEC_SP,
	SPEC_CY,
	SPEC_NO
};

struct s_sphere
{
	t_vec	center;
	double	diameter;
	double	radius;
};

struct s_plane
{
	t_vec	center;
	t_vec	normal;
};

struct s_cylinder
{
	t_vec	center;
	t_vec	normal;
	double	height;
	double	diameter;
	double	radius;
};

struct s_light
{
	t_vec	spot;
	double	ratio;
	int		count;
};

struct s_ray
{
	t_point	orig;
	t_vec	dir;
};

struct s_ambient
{
	double	ratio;
	t_color	color;
	int		count;
};

struct s_obj {
	enum e_type	type;
	void		*info;
	t_color		color;
	t_obj		*next;
};

struct s_cam {
	t_vec	origin;
	t_vec	dir;
	t_vec	up;
	double	fov;
	double	focal_len;
	t_vec	basis_i;
	t_vec	basis_j;
	t_vec	basis_k;
};

struct s_view {
	double	width;
	double	height;
	t_vec	**matrix;
};

struct s_scene {
	t_cam	cam;
	t_view	view;
	int		count;
};

struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	double		tmin;
	double		tmax;
	double		t;
	int			front_face;
	t_color		color;
};

struct s_data {
	void			*mlx_ptr;
	t_win			win;
	t_img			img;
	t_scene			scene;
	t_obj			*first_obj;
	t_light			light;
	t_ambient		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

int		ft_isfloatform(char *str);
int		ft_isvecform(char *str);
int		ft_iscolorform(char *str);
int		ft_isintform(char *str);

void	parse(int fd, struct s_data *data);
void	parse_ambient(struct s_data *data, char *strv[]);
void	parse_light(struct s_data *data, char *strv[]);
void	parse_camera(struct s_data *data, char *strv[]);
void	parse_plane(struct s_data *data, char *strv[]);
void	parse_sphere(struct s_data *data, char *strv[]);
void	parse_cylinder(struct s_data *data, char *strv[]);
void	add_object_front(t_obj **first_obj, t_obj *new);

#endif
