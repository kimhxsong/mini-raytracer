/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:46 by yookim            #+#    #+#             */
/*   Updated: 2022/01/19 02:08:48 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "minirt.h"

void		draw_scene(t_data *data);
t_color		color(double t, double r, double g, double b);
t_ray		ray(t_point orig, t_vec dir);

#endif
