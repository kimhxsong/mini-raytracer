/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:21:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 16:11:06 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void    str_to_vec(t_vec *vec, char *str)
{

	vec->i  = atof(strtok(str, ","));
	vec->j  = atof(strtok(NULL, ","));
	vec->k  = atof(strtok(NULL, ","));
}

void	str_to_color(t_color *color, char *str)
{
	color->t = 0;
	color->r = atof(strtok(str, ","));
	color->g = atof(strtok(NULL, ","));
	color->b = atof(strtok(NULL, ","));
}

// int	check_str_color(char *str, double max, double min)
// {
// 	char	*temp;

// 	temp = str;
// 	while (*temp)
// 		if (isdigit(*str, ))
// 			error();
	
// }

// check_vec_color(char *str, double max, double min)
// {
// 	char	*tmp;

// 	temp = str
// 	while (*str)
// 	{
// 		is
// 	}
// 	str = temp;
// }


