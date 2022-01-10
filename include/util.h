/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:26 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 21:32:39 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  UTIL_H
# define UTIL_H

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

char	*get_next_line(int fd);
char	**ft_split(char *input, const char *sep);

#endif
