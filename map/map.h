#ifndef IMAGE_H
# define IMAGE_H

# include <math.h>
# include "data.h"

void		draw_map(t_data *data);
void		rotate_map(t_data *data);
void		put_info(t_data *data);
void		print_map(t_data *data);
void		shift_map(t_data *data, int x, int y);

#endif
