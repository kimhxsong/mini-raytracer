/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/11 18:13:40 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static void	init_funcptr(void (*fp[6])(t_data *, char *[]))
{
	fp[0] = parse_ambient;
	fp[1] = parse_camera;
	fp[2] = parse_light;
	fp[3] = parse_plane;
	fp[4] = parse_sphere;
	fp[5] = parse_cylinder;
}

void	parse(int fd, t_data *data)
{
	char	*line;
	char	**strv;
	void	(*fp[6])(t_data *, char *[]);

	if (fd < 0)
	{
		mlx_destroy_window(data->mlx_ptr, data->win.ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
		ft_error(".rt file cannot be opened");
	}
	init_funcptr(fp);
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