/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:26:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/18 12:30:55 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_data *data, char *strv[])
{
	t_obj	*obj;
	t_plane	*pl;
	int		isform;

	if (ft_strvlen(strv) != 4)
		ft_error("Invalid 'plane' description");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_iscolorform(strv[3]);
	if (!isform)
		ft_error("Invalid 'plane' description");
	obj = (t_obj *)malloc(sizeof(t_obj));
	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!obj || !pl)
		ft_fatal("malloc");
	pl->center = ft_strtovec(strv[1]);
	pl->normal = ft_strtovec(strv[2]);
	obj->color = ft_strtocolor(strv[3]);
	obj->type = TYPE_PL;
	obj->info = pl;
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_sphere(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_sphere	*sp;
	int		isform;

	if (ft_strvlen(strv) != 4)
		ft_error("Invalid 'sphere' description");
	isform = ft_isvecform(strv[1]) && ft_isfloatform(strv[2]) \
		&& ft_iscolorform(strv[3]);
	if (!isform)
		ft_error("Invalid 'sphere' description");
	obj = (t_obj *)malloc(sizeof(t_obj));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !sp)
		ft_fatal("malloc");
	sp->center = ft_strtovec(strv[1]);
	sp->diameter = ft_atof(strv[2]);
	obj->color = ft_strtocolor(strv[3]);
	sp->radius = sp->diameter / 2;
	obj->type = TYPE_SP;
	obj->info = sp;
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_cylinder(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_cylinder	*cy;
	int		isform;

	if (ft_strvlen(strv) != 6)
		ft_error("Invalid 'cylinder' description");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_isfloatform(strv[3]) && ft_isfloatform(strv[4])
		&& ft_iscolorform(strv[5]);
	if (!isform)
		ft_error("Invalid 'cylinder' description");
	obj = (t_obj *)malloc(sizeof(t_obj));
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!obj || !cy)
		ft_fatal("malloc");
	cy->center = ft_strtovec(strv[1]);
	cy->normal = ft_strtovec(strv[2]);
	cy->diameter = ft_atof(strv[3]);
	cy->height = ft_atof(strv[4]);
	obj->color = ft_strtocolor(strv[5]);
	cy->radius = cy->diameter / 2;
	obj->type = TYPE_CY;
	obj->info = cy;
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}
