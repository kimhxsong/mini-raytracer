/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:06 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/11 18:17:21 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

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

char	*get_next_line(int fd)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	char		*newline;
	char		*lineptr;
	int			res;

	res = read(fd, buff, BUFFER_SIZE);
	if (res < 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	// if (!res && save)
	// {
	// 	lineptr = strdup(save);
	// 	save = NULL;
	// 	return (lineptr);
	// }
	if (!res && !save)
		return (NULL);
	if (!save)
		newline = NULL;
	else
		newline = strchr(save, '\n');
	temp = save;
	if (newline)
	{
		*newline = '\0';
		lineptr = strdup(save);
		save = strjoin(++newline, buff);
		free(temp);
		return (lineptr);
	}
	newline = strchr(buff, '\n');
	while (!newline)
	{
		save = strjoin(save, buff);
		free(temp);
		temp = save;
		if (!read(fd, buff, BUFFER_SIZE))
			break ;
		newline = strchr(buff, '\n');
	}
	if (newline)
	{
		*newline = '\0';
		lineptr = strjoin(save, buff);
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

/* int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = STDIN_FILENO;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		puts(line);
		free(line);
		line = get_next_line(fd);
	}
} */
