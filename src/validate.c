/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:52:47 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 16:31:58 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parse.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void	ft_error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, strlen(str));
	write(2, "\n", 1);
}

int	validate_file(char *file)
{
	char	*ext;

	ext = strrchr(file, '.');
	if (!ext || strcmp(ext, ".rt"))
	{
		ft_error("validate_file");
		return (1);
	}
	return (0);
}

int	validate_argc(int argc)
{
	if (argc != 2)
	{
		ft_error("validate_argc");
		return (1);
	}
	return (0);
}

/* int	main(int argc, char **argv)
{
	if (validate_argc(argc) || validate_argv(argv[1]))
		return (1);
	return (0);
} */
