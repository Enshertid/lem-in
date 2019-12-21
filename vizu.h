#ifndef LEM_IN_VIZU_H
#define LEM_IN_VIZU_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mlx.h"
#include "libft.h"

# ifdef __unix__

# else

/*
* window size
*/
# define WIDTH		2500
# define HEIGHT		1350
# define MAX_X (WIDTH - 1)
# define MAX_Y (HEIGHT - 1)

/*
* arrows
*/
#  define UP			126
#  define DOWN			125
#  define LEFT			123
#  define RIGHT			124

/*
* rotate keys
*/
#  define W				13
#  define S				1
#  define A				0
#  define D				2
#  define Q				12
#  define E				14

/*
* exit
*/
# define ESC			53

/*
* mouse
*/
#  define LEFT_BUTTON	1

# endif

# define __WHITE		16777215

/*
* flags
*/
# define FLAG_Z		1

typedef struct		s_mouse
{
	t_int32 		x;
	t_int32 		y;
	t_bool 			right;
	t_bool 			left;
}					t_mouse;

typedef struct		s_wnd
{
	void			*mlxptr;
	void			*wndptr;
	void			*imgptr;

	char			*img;
	int				bytes;
	int				size_line;
	int				endian;

	t_int32			x_offset;
	t_int32			y_offset;

	t_mouse 		mouse;
}					t_wnd;

typedef struct		s_angles
{
	t_int16			x;
	t_int16 		y;
	t_int16			z;
}					t_angles;

typedef struct		s_room
{
	t_int32			x;
	t_int32			y;
	t_int32 		z;
	char			*name;
	struct s_room	**links;
}					t_room;

typedef struct		s_graph
{
	t_uint32		ants;
	t_room			*rooms;
	t_int32			x_center;
	t_int32			y_center;
}					t_graph;

typedef struct		s_animation
{
	t_bool 			is_active;
}					t_animation;

typedef struct		s_data
{
	t_wnd 			wnd;
	t_graph			graph;
	t_animation		animation;
	t_uint64 		flags;
}					t_data;

typedef struct	s_point
{
	t_int32		x;
	t_int32		y;
	float		red;
	float		green;
	float		blue;
}				t_point;



t_data				get_input(const char **argv);
t_graph				get_graph(const char **argv);

void				draw_map(t_data *data);
void				draw_line(t_wnd *wnd, t_point a, t_point b);

int					mouse_press(int button, int x, int y, t_data *data);
int					mouse_release(int button, int x, int y, t_data *data);
int					mouse_move(int x, int y, t_data *data);

int					key_press(int keycode, t_data *data);

int					animation(t_data *data);

int					vizu_exit(t_data *data);

#endif
