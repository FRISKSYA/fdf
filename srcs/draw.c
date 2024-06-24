/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:55:24 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/24 13:31:01 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(int xa, int xb, int ya, int yb, t_fdf *data)
{
	int	dx;
	int	dy;
	int	e;
	int	y;
	int	x;

	dx = xb - xa;
	dy = yb - ya;
	e = 0;
	y = ya;
	x = xa;
	while (x <= xb)
	{
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		e = e + 2 * dy;
		if (e >= dx)
		{
			y++;
			e = e - 2 * dx;
		}
		x++;
	}
}
