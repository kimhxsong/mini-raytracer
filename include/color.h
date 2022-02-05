/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:50:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 14:21:19 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color {
	double	t;
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	color(double t, double r, double g, double b);
t_color	col_mult(t_color col1, double t);
t_color	col_plus(t_color col1, t_color col2);
t_color	col_min(t_color col1, t_color col2);
t_color	col_multc(t_color c1, t_color c2);

#endif
