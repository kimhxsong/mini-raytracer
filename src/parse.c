/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/08 17:08:08 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_error(t_data *data, char *strv[])
{
	(void)data;
	if (!strv || !*strv || **strv == '#')
		return ;
	ft_error("parse_error: Invalid identifier");
}

static int	get_id(char *id)
{
	if (!id || *id == '#')
		return (SPEC_NO);
	if (ft_memcmp("A", id, 2) == 0)
		return (SPEC_A);
	if (ft_memcmp("C", id, 2) == 0)
		return (SPEC_C);
	if (ft_memcmp("L", id, 2) == 0)
		return (SPEC_L);
	if (ft_memcmp("pl", id, 3) == 0)
		return (SPEC_PL);
	if (ft_memcmp("sp", id, 3) == 0)
		return (SPEC_SP);
	if (ft_memcmp("cy", id, 3) == 0)
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
	char	*line;
	char	**strv;

	if (fd < 0)
		ft_fatal("open");
	line = get_next_line(fd);
	if (!line)
		ft_error("parse: Empty file");
	while (line)
	{
		strv = ft_split(line, " \t\n");
		free(line);
		g_parser[get_id(strv[0])].fn(data, strv);
		ft_strvfree(strv);
		line = get_next_line(fd);
	}
	if (!data->scene.count || !data->ambient.count || !data->light.count)
		ft_error("parse: One or more identifiers are not declared.");
	close(fd);
}
