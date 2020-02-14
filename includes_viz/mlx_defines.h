/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:40:22 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/05 16:22:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DEFINES_H
# define MLX_DEFINES_H

# ifdef __unix__

#  define SYSTEM		"Linux"

#  define WIDTH			1800
#  define HEIGHT		1000

#  define ESC			65307

#  define MINUS			45
#  define PLUS			61

#  define SPACE			32

#  define W				119
#  define S				115
#  define A				97
#  define D				100

#  define Q				113
#  define E				101

#  define UP			65362
#  define DOWN			65364
#  define LEFT			65361
#  define RIGHT			65363

#  define I				105
#  define R				114

#  define WHEEL_UP		5
#  define WHEEL_DOWN	4

#  define LEFT_BUTTON	1
#  define RIGHT_BUTTON	3

#  define TAB			65289
#  define ENTER			65293

# else

#  define SYSTEM		"MacOS"

#  define WIDTH			2500
#  define HEIGHT		1350

#  define ESC			53

#  define MINUS			27
#  define PLUS			24

#  define SPACE			49

#  define W				13
#  define S				1
#  define A				0
#  define D				2

#  define Q				12
#  define E				14

#  define UP			126
#  define DOWN			125
#  define LEFT			123
#  define RIGHT			124

#  define I				34
#  define T				17
#  define R				15

#  define WHEEL_UP		5
#  define WHEEL_DOWN	4

#  define LEFT_BUTTON	1
#  define RIGHT_BUTTON	2

#  define TAB			48
#  define ENTER			36

#  define LESS			43
#  define MORE			47

# endif

# define MAX_X			(WIDTH - 1)
# define MAX_Y			(HEIGHT - 1)

# define __WHITE		0xFFFFFF
# define __RED			0xFF0000
# define __GREEN		0x00FF00
# define __BLUE			0x0000FF
# define __BLACK		0
# define __BROWN		0x583B00

#endif
