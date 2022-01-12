/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:26:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/12 17:16:28 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_data *data, char *strv[])
{
	t_obj	*obj;
	t_plane	*pl;

	obj = (t_obj *)malloc(sizeof(t_obj));
	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!obj || !pl)
	{
		free(obj);
		free(pl);
		return ;
	}
	pl->center.i  = atof(strtok(strv[1], ","));
	pl->center.j  = atof(strtok(NULL, ","));
	pl->center.k  = atof(strtok(NULL, ","));
	pl->normal.i  = atof(strtok(strv[2], ","));
	pl->normal.j  = atof(strtok(NULL, ","));
	pl->normal.k  = atof(strtok(NULL, ","));
	obj->type = TYPE_PL;
	obj->info = pl;
	obj->color.t = 0;
	obj->color.r = atof(strtok(strv[3], ","));
	obj->color.g = atof(strtok(NULL, ","));
	obj->color.b = atof(strtok(NULL, ","));
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_sphere(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_sphere	*sp;

	obj = (t_obj *)malloc(sizeof(t_obj));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !sp)
	{
		free(obj);
		free(sp);
		return ;
	}
	sp->center.i  = atof(strtok(strv[1], ","));
	sp->center.j  = atof(strtok(NULL, ","));
	sp->center.k  = atof(strtok(NULL, ","));
	sp->diameter = atof(strv[2]);
	sp->radius = sp->diameter / 2;
	obj->type = TYPE_SP;
	obj->info = sp;
	obj->color.t = 0;
	obj->color.r = atof(strtok(strv[3], ","));
	obj->color.g = atof(strtok(NULL, ","));
	obj->color.b = atof(strtok(NULL, ","));
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_cylinder(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_cylinder	*cy;

	obj = (t_obj *)malloc(sizeof(t_obj));
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!obj || !cy)
	{
		free(obj);
		free(cy);
		return ;
	}
	cy->center.i  = atof(strtok(strv[1], ","));
	cy->center.j  = atof(strtok(NULL, ","));
	cy->center.k  = atof(strtok(NULL, ","));
	cy->normal.i  = atof(strtok(strv[2], ","));
	cy->normal.j  = atof(strtok(NULL, ","));
	cy->normal.k  = atof(strtok(NULL, ","));
	cy->height = atof(strv[3]);
	cy->diameter = atof(strv[4]);
	cy->radius = cy->diameter / 2;
	obj->type = TYPE_CY;
	obj->info = cy;
	obj->color.t = 0;
	obj->color.r = atof(strtok(strv[5], ","));
	obj->color.g = atof(strtok(NULL, ","));
	obj->color.b = atof(strtok(NULL, ","));
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}