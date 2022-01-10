/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 16:59:12 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "minirt.h"

void	parse_ambient(t_data *data, char *strv[])
{
	puts(strv[0]);
	// data->ambient.ratio = atof(strv[0]);

	// data->ambient.color.r = atof(strtok(strv[1], ","));
	// data->ambient.color.g = atof(NULL);
	// data->ambient.color.b = atof(NULL);
}

void	parse_light(t_data *data, char *strv[])
{
	puts(strv[0]);
// 	data->light.spot.i = atof(strtok(strv[0], ","));
// 	data->light.spot.j = atof(strtok(NULL, ","));
// 	data->light.spot.k = atof(strtok(NULL, ","));

// 	data->light.ratio = atof(strv[1]);
}

void	parse_camera(t_data *data, char *strv[])
{
	puts(strv[0]);
	// data->cam.ray.origin.i = atof(strtok(strv[0], ","));
	// data->cam.ray.origin.j = atof(strtok(NULL, ","));
	// data->cam.ray.origin.k = atof(strtok(NULL, ","));

	// data->cam.ray.dir.i = atof(strtok(strv[1], ","));
	// data->cam.ray.dir.j = atof(strtok(NULL, ","));
	// data->cam.ray.dir.k = atof(strtok(NULL, ","));
	// data->cam.ray.fov = atof(strv[2]);
}

void	parse_plane(t_data *data, char *strv[])
{
	puts(strv[0]);
	// t_obj	*obj;
	// t_plane *pl;

	// obj = (t_obj *)malloc(sizeof(t_obj));
	// obj->type = TYPE_PL;
	// pl = (t_plane *)malloc(sizeof(t_plane));

	// pl->center.i  = atof(strtok(strv[0]), ",");
	// pl->center.j  = atof(strtok(NULL, ",");
	// pl->center.k  = atof(strtok(NULL, ",");

	// pl->dir.i  = atof(strtok(strv[1]), ",");
	// pl->dir.j  = atof(strtok(NULL, ",");
	// pl->dir.k  = atof(strtok(NULL, ",");

	// pl->color.r = atof(strtok(strv[2], ","));
	// pl->color.g = atof(NULL));
	// pl->color.b = atof(NULL));

	// add_object_front(&data->first_obj, obj);
}

void	parse_sphere(t_data *data, char *strv[])
{
	puts(strv[0]);
	// t_obj	*obj;
	// t_plane *pl;

	// obj = (t_obj *)malloc(sizeof(t_obj));
	// obj->type = TYPE_SP;
	// obj->info = (t_plane *)malloc(sizeof(t_plane));

	// pl->center.i  = atof(strtok(strv[0]), ",");
	// pl->center.j  = atof(strtok(NULL, ",");
	// pl->center.k  = atof(strtok(NULL, ",");

	// pl->dir.i  = atof(strtok(strv[1]), ",");
	// pl->dir.j  = atof(strtok(NULL, ",");
	// pl->dir.k  = atof(strtok(NULL, ",");

	// pl->color.r = atof(strtok(strv[2], ","));
	// pl->color.g = atof(NULL));
	// pl->color.b = atof(NULL));

	// add_object_front(&data->first_obj, obj);
}

void	parse_cylinder(t_data *data, char *strv[])
{
	puts(strv[0]);
	// t_obj	*obj;
	// t_plane *pl;

	// obj = (t_obj *)malloc(sizeof(t_obj));
	// obj->type = TYPE_CY;
	// pl = (t_plane *)malloc(sizeof(t_plane));

	// pl->center.i  = atof(strtok(strv[0]), ",");
	// pl->center.j  = atof(strtok(NULL, ",");
	// pl->center.k  = atof(strtok(NULL, ",");

	// pl->dir.i  = atof(strtok(strv[1]), ",");
	// pl->dir.j  = atof(strtok(NULL, ",");
	// pl->dir.k  = atof(strtok(NULL, ",");

	// pl->color.r = atof(strtok(strv[2], ","));
	// pl->color.g = atof(NULL));
	// pl->color.b = atof(NULL));

	// add_object_front(&data->first_obj, obj);
}

enum e_spec {
	SPEC_A,
	SPEC_C,
	SPEC_L,
	SPEC_PL,
	SPEC_SP,
	SPEC_CY
};

int	specify_identify(char *id)
{
	if (strcmp("A", id))
		return (SPEC_A);
	if (strcmp("C", id))
		return (SPEC_C);
	if (strcmp("L", id))
		return (SPEC_L);
	if (strcmp("pl", id))
		return (SPEC_PL);
	if (strcmp("sp", id))
		return (SPEC_SP);
	if (strcmp("cy", id))
		return (SPEC_CY);
	else
	{
		write(2, "Error\n", 6);
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
	int		fd;
	void	(*fp[6])(t_data *, char *[]);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("parser_description");
		exit(EXIT_FAILURE);
	}
	close(fd);
	init_fp(fp);

	fp[0](NULL, (char *[]){"0", NULL});
	fp[1](NULL, (char *[]){"1", NULL});
	fp[2](NULL, (char *[]){"2", NULL});
	fp[3](NULL, (char *[]){"3", NULL});
	fp[4](NULL, (char *[]){"4", NULL});
	fp[5](NULL, (char *[]){"5", NULL});
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		break ;
	// 	strv = ft_split(line);
	// 	fp[specify_identifier(strv[0])](data, &strv[1]);
	// 	free(line);
	// }
}
