/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/03 17:43:34 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024;
#endif

int	gnl_error(int fd, char buff[], char **ref_save)
{
	int	res;

	if (fd >= 0)
		res = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || res < 0)
	{
		free(*ref_save);
		*ref_save = NULL;
		return (-1);
	}
	if (!res && !*ref_save)
		return (-1);
	return (0);
}

char	*gnl_from_save(char buff[], char **ref_save, char **ref_newline)
{
	char	*newline;
	char	*lineptr;
	char	*old_save;

	newline = *ref_newline;
	old_save = *ref_save;
	*newline = '\0';
	lineptr = ft_strdupnl(old_save);
	*ref_save = ft_strjoin(++newline, buff);
	free(old_save);
	return (lineptr);
}

int	gnl_read_buff(int fd, char buff[], char **ref_save, char **ref_newline)
{
	char	*newline;
	char	*old_save;
	int		res;

	newline = strchr(buff, '\n');
	res = 1;
	while (!newline)
	{
		old_save = *ref_save;
		*ref_save = ft_strjoin(old_save, buff);
		free(old_save);
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
			break ;
		newline = ft_strchr(buff, '\n');
	}
	if (res < 0)
	{
		free(*ref_save);
		*ref_save = NULL;
		return (-1);
	}
	*ref_newline = newline;
	return (0);
}

char	*gnl_from_buff(char buff[], char **ref_save, char **ref_newline)
{
	char	*old_save;
	char	*newline;
	char	*lineptr;

	old_save = *ref_save;
	newline = *ref_newline;
	if (newline)
	{
		*newline = '\0';
		lineptr = ft_strjoinnl(old_save, buff);
		*ref_save = ft_strdup(++newline);
	}
	else
	{
		lineptr = ft_strdup(old_save);
		*ref_save = NULL;
	}
	free(old_save);
	return (lineptr);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save;
	char		*newline;

	ft_memset(buff, 0, BUFFER_SIZE + 1);
	if (gnl_error(fd, buff, &save) < 0)
		return (NULL);
	newline = NULL;
	if (save)
	{
		newline = ft_strchr(save, '\n');
		if (newline)
			return (gnl_from_save(buff, &save, &newline));
	}
	if (gnl_read_buff(fd, buff, &save, &newline) < 0)
		return (NULL);
	return (gnl_from_buff(buff, &save, &newline));
}
