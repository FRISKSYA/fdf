/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:40:57 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/24 13:21:14 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// libs
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_fdf
{
	// mlx
	void	*mlx;
	void	*mlx_win;
	// img
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian; // FIXME: del???
	// map
	int		width;
	int		height;
	int		**z_matrix;
}			t_fdf;

typedef enum	s_hooks
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}			t_hooks;

// draw funcs
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		add_shade(double distance, int color);
int		get_opposite(int color);

// encode & decode color
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// demo
void	read_file(char *file_name, t_fdf *data);
void	bresenham(int xa, int xb, int ya, int yb, t_fdf *data);

#endif
