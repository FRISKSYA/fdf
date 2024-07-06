/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:40:57 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/05 19:20:44 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// libs
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <X11/X.h>
# include <X11/keysym.h>

// window vars
# define WIDTH 1920
# define HEIGHT 1080
# define ZOOM_BASE 50
// Linux esc
# define ESC 65307

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	float	rotation;
}			t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;

typedef enum s_hooks
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}			t_hooks;

// fdf main

// draw funcs
void		my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void		draw(t_fdf *data);

// read_files
int			malloc_data(char *file_name, t_fdf *data);
int			read_file(char *file_name, t_fdf *data);
int			get_height(char *file_name);
int			get_width(char *file_name);

// math
int			ft_max(float a, float b);
int			ft_mod(float f);
void		isometric(float *x, float *y, int z);

// exit funcs
int			close_by_esc(int key, t_fdf *data);
int			exit_program(t_fdf *data);
#endif
