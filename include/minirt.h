/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:38:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 06:58:57 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


#include "libftx.h"

# ifndef WIN_SIZE_X
#  define WIN_SIZE_X 1920
# endif

# ifndef WIN_SIZE_Y
#  define WIN_SIZE_Y 1080
# endif

# define _USE_MATH_DEFINES

# define ESC 53
# define TRUE 1
# define FALSE 0
# define EPSILON 1e-6
# define LUMEN 3

typedef enum e_type {
	TYPE_SP,
	TYPE_PL,
	TYPE_CY
}	t_type;

enum e_spec {
	SPEC_A,
	SPEC_C,
	SPEC_L,
	SPEC_PL,
	SPEC_SP,
	SPEC_CY,
	SPEC_NO
};

typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;
typedef struct s_light t_light;
typedef struct s_ambient t_ambient;
typedef struct s_obj t_obj;
typedef struct s_cam    t_cam;
typedef struct s_view   t_view;
typedef struct s_scene    t_scene;
typedef struct s_hit_record t_hit_record;
typedef struct s_data t_data;

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
    t_vec   center;
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

struct s_ambient
{
	double	ratio;
	t_color	color;
	int		count;
};

struct s_obj {
	t_type		type;
	void		*info;
	t_color		color;
	t_obj	*next;
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

typedef struct s_ray
{
	t_point	orig;	// 정점.시작점
	t_vec	dir;    // 방향 벡터(단위 벡터O)
} t_ray;

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

#include "parse.h"
#include "draw.h"
#include "hit.h"
#include "light.h"
#include "color.h"

void    init_data(char *argv[], t_data *data);
void    init_scene(t_data *data);
void    listen_event(t_data *data);

#endif
