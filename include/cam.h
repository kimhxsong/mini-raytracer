/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:46:01 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 17:14:24 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CAM_H
# define CAM_H

#include "minirt.h"

typedef struct s_cam    t_cam;
typedef struct s_view   t_view;

struct s_cam {
    t_vec           origin;
    t_vec           dir;
    const t_vec     up;
    float           fov;
    float           focal_len;
    t_vec           basis_i;
    t_vec           basis_j;
    t_vec           basis_k;
};

struct s_view {
    int             width;
    int             height;
    t_vec           **image;
};

#endif
