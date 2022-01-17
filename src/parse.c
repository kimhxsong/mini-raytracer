/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 19:52:23 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	handle_invalid(t_data *data, char *strv[])
{
	ft_error("Invalid identifier");
}

static int	get_id(char *id)
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
	return (SPEC_NO);
}

static void	init_funcptr(void (*fp[7])(t_data *, char *[]))
{
	fp[0] = parse_ambient;
	fp[1] = parse_camera;
	fp[2] = parse_light;
	fp[3] = parse_plane;
	fp[4] = parse_sphere;
	fp[5] = parse_cylinder;
	fp[6] = handle_invalid;
}

void	parse(int fd, t_data *data)
{
	char	*line;
	char	**strv;
	void	(*fp[7])(t_data *, char *[]);

	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty file");
	init_funcptr(fp);
	while (line && *line)
	{
		strv = ft_split(line, " \t");
		free(line);
		fp[get_id(strv[0])](data, strv);
		ft_strvfree(strv);
		line = get_next_line(fd);
	}
	close(fd);
}
