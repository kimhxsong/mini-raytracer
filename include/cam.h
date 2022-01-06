/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:46:01 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/05 17:54:02 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CAM_H
# define CAM_H

#include "minirt.h"

typedef struct s_cam t_cam;
typedef struct s_view   t_view;

struct s_cam {
    t_vec           origin;
    t_vec           dir;
    t_vec           basis[3];
    t_vec           up;
    float           fov;
    float           focus_len;
};

struct s_view {
    t_vec           center;
    int             width;
    int             height;
    int             **image;
};

#endif
