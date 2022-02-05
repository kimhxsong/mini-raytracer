/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:35:48 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/04 06:10:34 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	validate_args(int argc, char *argv[])
{
	char	*ext;

	if (argc != 2)
		ft_error("validate_args: Invalid argument");
	ext = ft_strrchr(argv[1], '.');
	if (!ext || ft_memcmp(ext, ".rt", 4 * sizeof(unsigned char)))
		ft_error("validate_args: Invalid file");
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
