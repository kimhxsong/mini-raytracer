/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/12 12:59:09 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static char *strdupnl(char *str)
{
	char	*new;
	size_t	len;
	int		i;

	len = strlen(str);
	new = (char *)malloc((len + 2) * sizeof(char));
	i = -1;
	while (++i < len)
		new[i] = str[i];
	new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

static char	*strjoin(char *str1, char *str2)
{
	char	*join;
	char	*temp;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (strdup(str2));
	if (str1 && !str2)
		return (strdup(str1));
	join = (char *)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	temp = join;
	while (*str1)
		*temp++ = *str1++;
	while (*str2)
		*temp++ = *str2++;
	*temp = '\0';
	return (join);
}

static char	*strjoinnl(char *str1, char *str2)
{
	char	*join;
	char	*temp;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (strdupnl(str2));
	if (str1 && !str2)
		return (strdupnl(str1));
	join = (char *)malloc((strlen(str1) + strlen(str2) + 2) * sizeof(char));
	if (!join)
		return (NULL);
	temp = join;
	while (*str1)
		*temp++ = *str1++;
	while (*str2)
		*temp++ = *str2++;
	*temp++ = '\n';
	*temp = '\0';
	return (join);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	char		*newline;
	char		*lineptr;
	int			res;

	temp = save;
	memset(buff, 0, BUFFER_SIZE + 1);
	res = read(fd, buff, BUFFER_SIZE);
	if (res < 0)
	{
		free(temp);
		save = NULL;
		return (NULL);
	}
	if (!res && !save)
		return (NULL);
	newline = NULL;
	if (save)
		newline = strchr(save, '\n');
	if (newline)
	{
		*newline = '\0';
		lineptr = strdupnl(save);
		save = strjoin(++newline, buff);
		free(temp);
		return (lineptr);
	}
	newline = strchr(buff, '\n');
	while (res && !newline)
	{
		save = strjoin(save, buff);
		free(temp);
		temp = save;
		res = read(fd, buff, BUFFER_SIZE);
		newline = strchr(buff, '\n');
	}
	if (res < 0)
	{
		free(temp);
		save = NULL;
		return (NULL);
	}
	if (newline)
	{
		*newline = '\0';
		lineptr = strjoinnl(save, buff);
		save = strdup(++newline);
	}
	else
	{
		lineptr = strdup(save);
		save = NULL;
	}
	free(temp);
	return (lineptr);
}
