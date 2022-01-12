/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/12 17:58:36 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	handle_execption(t_data *data, char *strv[])
{
	t_obj	*curr;
	void	*del;
	int		i;

	if (*strv[0] == '\n')
		return ;
	mlx_destroy_window(data->mlx_ptr, data->win.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	curr = data->first_obj;
	while (curr)
	{
		free(curr->info);
		del = curr;
		curr = curr->next;
		free(del);
	}
	ft_strvfree(strv);
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
	fp[6] = handle_execption;
}

void	parse(int fd, t_data *data)
{
	char	*line;
	char	**strv;
	void	(*fp[7])(t_data *, char *[]);

	line = get_next_line(fd);
	if (fd < 0 || !line)
	{
		mlx_destroy_window(data->mlx_ptr, data->win.ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
		if (fd < 0)
			ft_error(strerror(2));
		if (!line)
			ft_error("Empty file");
		
	}
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
