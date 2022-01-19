/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:08:55 by yookim            #+#    #+#             */
/*   Updated: 2022/01/19 02:08:56 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "minirt.h"

t_color	lighting(t_data *data);
// 아래 4개의 함수는 t_color의 t_vec으로 통일이 되면 없어진다.
t_color	vec_mult_c(t_color col1, double t);
t_color	vec_plus_c(t_color col1, t_color col2);
t_color	vec_min(t_color col1, t_color col2);
t_color	vec_multc(t_color c1, t_color c2);

#endif
