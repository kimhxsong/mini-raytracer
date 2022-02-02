/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:46 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 13:05:14 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "color.h"

typedef struct s_data	t_data;
typedef struct s_ray	t_ray;

void		draw_scene(t_data *data);
t_color		color(double t, double r, double g, double b);
t_ray		ray(t_point orig, t_vec dir);

#endif
