/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:00:58 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:18:46 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  IO_H
# define IO_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX _SC_OPEN_MAX
# endif

/*
 * stdout
 */
int	ft_putchar(int c);
int	ft_puts(const char *s);
int	ft_putendl(const char *s);
int	ft_putnbr(int n);
/*
 * with fd
 */
int	ft_dputchar(int fd, int c);
int	ft_dputs(int fd, const char *s);
int	ft_dputendl(int fd, const char *s);
int	ft_dputnbr(int fd, int n);

int	get_next_lineptr(int fd, char **lineptr);

#endif
