/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:44:44 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 17:27:41 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "minirt.h"

# define FOCAL_LEN 1.0f

void	parse_ambient(t_data *data, char *strv[]);
void	parse_light(t_data *data, char *strv[]);
void	parse_camera(t_data *data, char *strv[]);

void	parse(int fd, t_data *data);
void	parse_plane(t_data *data, char *strv[]);
void	parse_sphere(t_data *data, char *strv[]);
void	parse_cylinder(t_data *data, char *strv[]);
void	add_object_front(t_obj **first_obj, t_obj *new);

int		ft_isfloatform(char *str);
int		ft_isvecform(char *str);
int		ft_iscolorform(char *str);
int		ft_isintform(char *str);

#endif
