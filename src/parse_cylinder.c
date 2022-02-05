/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 06:03:32 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_cylinder(char *strv[])
{
	int	isform;

	if (ft_strvlen(strv) != 6)
		ft_error("validate_cylinder: Invalid description");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_isfloatform(strv[3]) && ft_isfloatform(strv[4])
		&& ft_iscolorform(strv[5]);
	if (!isform)
		ft_error("validate_cylinder: Invalid description");
}

static void	init_obj_cylinder(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_cylinder	*cy;

	obj = (t_obj *)malloc(sizeof(t_obj));
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!obj || !cy)
		ft_fatal("malloc");
	cy->center = ft_strtovec(strv[1]);
	cy->normal = ft_strtovec(strv[2]);
	if (!ft_isunitvec(cy->normal))
		ft_error("init_obj_cylinder: Invalid 3d normalized orientation vector");
	cy->diameter = ft_atof(strv[3]);
	cy->height = ft_atof(strv[4]);
	if (cy->diameter < 0)
		ft_error("init_obj_cylinder: Invalid diameter");
	if (cy->height < 0)
		ft_error("init_obj_cylinder: Invalid height");
	obj->color = ft_strtocolor(strv[5]);
	if (!ft_iscolor(obj->color))
		ft_error("init_obj_cylinder: Invalid RGB");
	cy->radius = cy->diameter / 2;
	obj->type = TYPE_CY;
	obj->info = cy;
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_cylinder(t_data *data, char *strv[])
{
	validate_cylinder(strv);
	init_obj_cylinder(data, strv);
}
