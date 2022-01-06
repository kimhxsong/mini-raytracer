/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:38:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 16:56:59 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "mlxx.h"
#include "vec.h"
#include "cam.h"

struct s_data {
	void	*mlx_ptr;
	t_win	win;
	t_img	img;
	t_cam	cam;
	t_view	view;
}

#endif