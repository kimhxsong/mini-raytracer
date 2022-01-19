/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:02 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/19 15:50:58 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_sphere(char *strv[])
{
	int		isform;

	if (ft_strvlen(strv) != 4)
		ft_error("Invalid 'sphere' description");
	isform = ft_isvecform(strv[1]) && ft_isfloatform(strv[2]) \
		&& ft_iscolorform(strv[3]);
	if (!isform)
		ft_error("Invalid 'sphere' description");
}

static void	init_obj_sphere(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_sphere	*sp;

	obj = (t_obj *)malloc(sizeof(t_obj));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !sp)
		ft_fatal("malloc");
	sp->center = ft_strtovec(strv[1]);
	sp->diameter = ft_atof(strv[2]);
	obj->color = ft_strtocolor(strv[3]);
	if (!ft_iscolor(obj->color))
		ft_error("Invalid 'sphere' RGB");
	sp->radius = sp->diameter / 2;
	obj->type = TYPE_SP;
	obj->info = sp;
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_sphere(t_data *data, char *strv[])
{
	validate_sphere(strv);
	init_obj_sphere(data, strv);
}
