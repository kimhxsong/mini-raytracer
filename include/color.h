#ifndef COLOR_H
# define COLOR_H
# include "libftx.h"

t_color	col_mult(t_color col1, double t);
t_color	col_plus(t_color col1, t_color col2);
t_color	col_min(t_color col1, t_color col2);
t_color	col_multc(t_color c1, t_color c2);

#endif
