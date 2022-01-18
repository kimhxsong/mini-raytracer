/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:38:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 02:03:02 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "libftx.h"
#include "vec.h"
#include "parse.h"
#include "draw.h"
#include "hit.h"
#include "light.h"

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

void    init_data(char *argv[], t_data *data);
void    init_scene(t_data *data);
void    listen_event(t_data *data);

void    init_data(char *argv[], t_data *data);
void    init_scene(t_data *data);
void    listen_event(t_data *data);

#endif
