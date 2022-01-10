/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:38:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 16:35:43 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "mlxx.h"
#include "cam.h"

typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;
typedef struct s_light t_light;
typedef struct s_ambient t_ambient;
typedef struct s_object t_obj;
typedef struct s_data t_data;

typedef enum e_type {
	TYPE_SP,
	TYPE_PL,
	TYPE_CY
}	t_type;

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
};

struct s_ambient
{
	double	ratio;
	t_color	color;
};

struct s_obj {
	t_type		type;
	void		*info;
	t_color		color;
	t_obj	*next;
};

struct s_data {
	void		*mlx_ptr;
	t_win		win;
	t_img		img;
	t_cam		cam;
	t_obj		*first_obj;
	t_light		light;
	t_ambient	ambient;
};

#include "event.h"
#include "parse.h"

#endif