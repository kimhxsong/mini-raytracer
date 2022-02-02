/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:29 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 14:46:07 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFTX_H
# define LIBFTX_H

# include "libft.h"
# include "mlx.h"
# include "color.h"
# include "vec.h"

typedef struct s_win	t_win;
typedef struct s_img	t_img;

struct s_win {
	void	*ptr;
	int		width;
	int		height;
};

struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
};

/** mlx extenstion */
void	mlx_img_init(void *mlx_ptr, t_win *win, t_img *img);
void	mlx_img_pixel_put(t_img *img, int color, int x, int y);
int		convert_rgb(t_color color);

/** libft extension */
void	ft_error(char *str);
void	ft_fatal(const char *str);
size_t	ft_strvlen(char **strv);
void	ft_strvfree(char *strv[]);
double	ft_atof(char *str);
int		ft_isinscope(double n, double max, double min);
int		ft_issign(int c);
t_color	ft_strtocolor(char *str);
t_vec	ft_strtovec(char *str);

int		ft_isunitvec(t_vec vec);
int		ft_iscolor(t_color color);

/** libft - latest get_next_line */
char	*get_next_line(int fd);

#endif
