/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/26 15:43:56 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static char *ft_strdupnl(char *str)
{
	char	*new;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	new = (char *)malloc((len + 2) * sizeof(char));
	i = -1;
	while (++i < len)
		new[i] = str[i];
	new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

static char	*ft_strjoinnl(char *str1, char *str2)
{
	char	*join;
	char	*temp;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (ft_strdupnl(str2));
	if (str1 && !str2)
		return (ft_strdupnl(str1));
	join = (char *)malloc((strlen(str1) + ft_strlen(str2) + 2) * sizeof(char));
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
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	if (fd >= 0)
		res = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || res < 0)
	{
		free(temp);
		save = NULL;
		return (NULL);
	}
	if (!res && !save)
		return (NULL);
	newline = NULL;
	if (save)
		newline = ft_strchr(save, '\n');
	if (newline)
	{
		*newline = '\0';
		lineptr = ft_strdupnl(save);
		save = ft_strjoin(++newline, buff);
		free(temp);
		return (lineptr);
	}
	newline = strchr(buff, '\n');
	while (res && !newline)
	{
		save = ft_strjoin(save, buff);
		free(temp);
		temp = save;
		res = read(fd, buff, BUFFER_SIZE);
		newline = ft_strchr(buff, '\n');
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
		lineptr = ft_strjoinnl(save, buff);
		save = ft_strdup(++newline);
	}
	else
	{
		lineptr = ft_strdup(save);
		save = NULL;
	}
	free(temp);
	return (lineptr);
}
