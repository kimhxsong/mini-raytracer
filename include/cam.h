/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:46:01 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/07 17:45:16 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CAM_H
# define CAM_H

#include "vec.h"

typedef struct s_ray    t_ray;
typedef struct s_view   t_view;
typedef struct s_cam    t_cam;

struct s_ray {
    t_vec   origin;
    t_vec   dir;
    t_vec   up;
    double   fov;
    double   focal_len;
    t_vec   basis_i;
    t_vec   basis_j;
    t_vec   basis_k;
};

struct s_view {
    double   width;
    double   height;
    t_vec   **matrix;
};

struct s_cam {
    t_ray   ray;
    t_view  view;
};

void    init_cam(t_cam *cam, double width, double height);

#endif
