/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:44:44 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 16:37:54 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "minirt.h"


void	ft_error(char *str);
int		validate_file(char *file);
int		validate_argc(int argc);

void	parse_description(char *path, t_data data);

#endif
