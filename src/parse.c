/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 22:49:16 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "minirt.h"

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}

void	parse_ambient(t_data *data, char *strv[])
{
	data->ambient.ratio = atof(strv[1]);
	data->ambient.color.t = 0;
	data->ambient.color.r = atof(strtok(strv[2], ","));
	data->ambient.color.g = atof(strtok(NULL, ","));
	data->ambient.color.b = atof(strtok(NULL, ","));
}

void	parse_light(t_data *data, char *strv[])
{
	data->light.spot.i = atof(strtok(strv[1], ","));
	data->light.spot.j = atof(strtok(NULL, ","));
	data->light.spot.k = atof(strtok(NULL, ","));
	data->light.ratio = atof(strv[2]);
}

void	parse_camera(t_data *data, char *strv[])
{
	data->cam.ray.origin.i = atof(strtok(strv[1], ","));
	data->cam.ray.origin.j = atof(strtok(NULL, ","));
	data->cam.ray.origin.k = atof(strtok(NULL, ","));
	data->cam.ray.dir.i = atof(strtok(strv[2], ","));
	data->cam.ray.dir.j = atof(strtok(NULL, ","));
	data->cam.ray.dir.k = atof(strtok(NULL, ","));
	data->cam.ray.fov = atof(strv[3]);
}

void	parse_plane(t_data *data, char *strv[])
{
	t_obj	*obj;
	t_plane *pl;

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

static int	specify_identifier(char *id)
{
	if (strcmp("A", id) == 0)
		return (SPEC_A);
	if (strcmp("C", id) == 0)
		return (SPEC_C);
	if (strcmp("L", id) == 0)
		return (SPEC_L);
	if (strcmp("pl", id) == 0)
		return (SPEC_PL);
	if (strcmp("sp", id) == 0)
		return (SPEC_SP);
	if (strcmp("cy", id) == 0)
		return (SPEC_CY);
	else
	{
		ft_error("parse_description");
		exit(1);
	}
}


void	init_fp(void (*fp[6])(t_data *, char *[]))
{
	fp[0] = parse_ambient;
	fp[1] = parse_camera;
	fp[2] = parse_light;
	fp[3] = parse_plane;
	fp[4] = parse_sphere;
	fp[5] = parse_cylinder;
}

void	parse_description(char *path, t_data *data)
{
	char	*line;
	char	**strv;
	int		fd;
	void	(*fp[6])(t_data *, char *[]);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("parser_description");
		exit(EXIT_FAILURE);
	}
	init_fp(fp);
	line = get_next_line(fd);
	while (line)
	{
		strv = ft_split(line, " ");
		free(line);
		fp[specify_identifier(strv[0])](data, strv);
		free(*strv);
		for (int i = 0; strv[i];)
			free(strv[++i]);
		free(strv);
		line = get_next_line(fd);
	}
	close(fd);
}
