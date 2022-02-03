/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 12:55:22 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_error(t_data *data, char *strv[])
{
	(void)data;
	if (!strv || !*strv || **strv == '#')
		return ;
	ft_error("Invalid identifier");
}

static int	get_id(char *id)
{
	if (!id || *id == '#')
		return (SPEC_NO);
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

static const t_parser	g_parser[] = {
	{parse_ambient},
	{parse_camera},
	{parse_light},
	{parse_plane},
	{parse_sphere},
	{parse_cylinder},
	{parse_error}
};

void	parse(int fd, t_data *data)
{
	char	*lineptr;
	char	**strv;

	if (fd < 0)
		ft_fatal("open");
	if (get_next_line(fd, &lineptr) == -1)
		ft_fatal("read");
	if (!lineptr)
		ft_error("Empty file");
	while (lineptr)
	{
		strv = ft_split(lineptr, " \t\n");
		free(lineptr);
		g_parser[get_id(strv[0])].fn(data, strv);
		ft_strvfree(strv);
		if (get_next_line(fd, &lineptr) == -1)
			ft_fatal("read");
	}
	if (!data->scene.count || !data->ambient.count || !data->light.count)
		ft_error("One or more identifiers are not declared.");
	close(fd);
}
