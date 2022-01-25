/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 05:16:31 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_error(t_data *data, char *strv[])
{
	if (!strv || !*strv || **strv == '#')
		return ;
	ft_error("Invalid identifier");
}

static int	_id(char *id)
{
	if (!id || *id == '#')
		return (SPEC_NO);
	if (ft_strcmp("A", id) == 0)
		return (SPEC_A);
	if (ft_strcmp("C", id) == 0)
		return (SPEC_C);
	if (ft_strcmp("L", id) == 0)
		return (SPEC_L);
	if (ft_strcmp("pl", id) == 0)
		return (SPEC_PL);
	if (ft_strcmp("sp", id) == 0)
		return (SPEC_SP);
	if (ft_strcmp("cy", id) == 0)
		return (SPEC_CY);
	return (SPEC_NO);
}

static const void (*g_parse_object[7])(t_data *, char *[]) = { \
	{parse_ambient}, \
	{parse_camera}, \
	{parse_light}, \
	{parse_plane}, \
	{parse_sphere}, \
	{parse_cylinder}, \
	{parse_error} \
};

void	parse(int fd, t_data *data)
{
	char	*line;
	char	**strv;
	void	(*fp[7])(t_data *, char *[]);

	if (fd < 0)
		ft_fatal("open");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty file");
	while (line)
	{
		strv = ft_split(line, " \t\n");
		free(line);
		g_parse_object[get_id(strv[0])](data, strv);
		ft_strvfree(strv);
		line = get_next_line(fd);
	}
	if (!data->scene.count || !data->ambient.count || !data->light.count)
		ft_error("One or more identifiers are not declared.");
	close(fd);
}
