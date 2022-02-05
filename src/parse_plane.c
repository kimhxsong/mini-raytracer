/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:04 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 06:01:36 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_plane(char *strv[])
{
	int	isform;

	if (ft_strvlen(strv) != 4)
		ft_error("validate_plane: Invalid description");
	isform = ft_isvecform(strv[1]) && ft_isvecform(strv[2]) \
		&& ft_iscolorform(strv[3]);
	if (!isform)
		ft_error("validate_plane: plane: Invalid description");
}

static void	init_obj_plane(t_data *data, char *strv[])
{
	t_obj	*obj;
	t_plane	*pl;

	obj = (t_obj *)malloc(sizeof(t_obj));
	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!obj || !pl)
		ft_fatal("malloc");
	pl->center = ft_strtovec(strv[1]);
	pl->normal = ft_strtovec(strv[2]);
	if (!ft_isunitvec(pl->normal))
		ft_error("init_obj_plane: Invalid 3d normalized orientation vector");
	obj->color = ft_strtocolor(strv[3]);
	if (!ft_iscolor(obj->color))
		ft_error("init_obj_plane: Invalid RGB");
	obj->type = TYPE_PL;
	obj->info = pl;
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_plane(t_data *data, char *strv[])
{
	validate_plane(strv);
	init_obj_plane(data, strv);
}
