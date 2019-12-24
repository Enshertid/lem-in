#ifndef LEM_IN_VIZU_H
#define LEM_IN_VIZU_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mlx.h"
#include "libft.h"

# ifdef __unix__

/*
 * windows size
 */
#  define WIDTH			1800
#  define HEIGHT		1000

/*
 * arrows
 */
#  define UP			65362
#  define DOWN			65364
#  define LEFT			65361
#  define RIGHT			65363

/*
 * rotate keys
 */
#  define W				119
#  define S				115
#  define A				97
#  define D				100
#  define Q				113
#  define E				101

/*
 * exit
 */
#  define ESC			65307

/*
 * mouse
 */
#  define LEFT_BUTTON	1

# else

/*
* window size
*/
# define WIDTH			2500
# define HEIGHT			1350

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
#  define ESC			53

#  define SPACE			49

/*
* mouse
*/
#  define LEFT_BUTTON	1
#  define WHEEL_UP		5
#  define WHEEL_DOWN	4

# endif

# define MAX_X			(WIDTH - 1)
# define MAX_Y			(HEIGHT - 1)

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

typedef struct		s_angles
{
	t_int16			x;
	t_int16 		y;
	t_int16			z;
}					t_angles;

typedef struct		s_image
{
	void		*imgptr;
	char		*img;
	int			bytes;
	int			size_line;
	int			endian;
}					t_image;

typedef struct		s_wnd
{
	void			*mlxptr;
	void			*wndptr;

	t_image			graph_img;
	t_image			ant_img;

	t_int32			x_offset;
	t_int32			y_offset;

	t_mouse 		mouse;
	t_angles		angles;
}					t_wnd;

typedef struct		s_room
{
	t_int32			x;
	t_int32			y;
	t_int32 		z;
	char			*name;
	struct s_room	**links;
	t_bool			is_draw;
}					t_room;

typedef struct 		s_coord
{
	t_int32			x;
	t_int32			y;
	t_int32			z;
}					t_coord;

typedef struct		s_graph
{
	t_room			*rooms;
	t_uint32		ants;
	t_uint32		z_scale;
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
	t_coord			*basic_coords;
	t_uint64 		flags;
}					t_data;

typedef struct	s_point
{
	t_int32		x;
	t_int32		y;
	t_int32		z;
	float		red;
	float		green;
	float		blue;
}				t_point;



t_data				get_input(const char **argv);
t_graph				get_graph(const char **argv);

void				draw_map(t_data *data);
void				draw_line(t_image *img, t_point a, t_point b);

void				some_configs(t_data *data);

int					mouse_press(int button, int x, int y, t_data *data);
int					mouse_release(int button, int x, int y, t_data *data);
int					mouse_move(int x, int y, t_data *data);

int					key_press(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);

int					animation(t_data *data);

int					vizu_exit(t_data *data);

#endif