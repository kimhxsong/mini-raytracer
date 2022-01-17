/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:35:48 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/13 18:02:28 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_args(int argc, char *argv[])
{
	char	*ext;

	if (argc != 2)
		ft_error("Invalid argument");
	ext = strrchr(argv[1], '.');
	if (!ext || strcmp(ext, ".rt"))
		ft_error("Invalid file");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	validate_args(argc, argv);
	init_data(argv, &data);
	draw_scene(&data);
	listen_event(&data);
	return (0);
}
