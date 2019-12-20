#ifndef LEM_IN_VIZU_H
#define LEM_IN_VIZU_H

#include <stdio.h>
#include "mlx.h"
#include "libft.h"

# define WIDTH		2500
# define HEIGHT		1350

# define ESC		53

typedef struct		s_wnd
{
	void			*mlxptr;
	void			*wndptr;
	void			*imgptr;

	char			*img;
	int				bytes;
	int				size_line;
	int				endian;
}					t_wnd;

typedef struct		s_room
{
	t_int32			x;
	t_int32			y;
	char			*name;
	struct s_room	**links;
}					t_room;

typedef struct		s_data
{
	t_room			*rooms;
	t_int32			ants;
}					t_data;

int					vizu_exit(t_wnd *wnd);
int					key_press(int keycode, t_wnd *wnd);
t_data				get_map(const char *file);


#endif
