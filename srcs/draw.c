/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:55:24 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/05 19:27:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	set_color(int z1, int z2)
{
	if (z1 || z2)
		return (0x00FF0000);
	else
		return (0x00FFFFFF);
}

static void	apply_zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

static t_point	get_steps(t_point p1, t_point p2)
{
	t_point	step;
	int		max;

	step.x = p2.x - p1.x;
	step.y = p2.y - p1.y;
	max = ft_max(ft_mod(step.x), ft_mod(step.y));
	step.x /= max;
	step.y /= max;
	return (step);
}

static void	bresenham(t_point p1, t_point p2, t_fdf *data)
{
	t_point	step;
	int		z1;
	int		z2;

	z1 = data->z_matrix[(int)p1.y][(int)p1.x];
	z2 = data->z_matrix[(int)p2.y][(int)p2.x];
	data->color = set_color(z1, z2);
	apply_zoom(&p1.x, &p1.y, data);
	apply_zoom(&p2.x, &p2.y, data);
	isometric(&p1.x, &p1.y, z1);
	isometric(&p2.x, &p2.y, z2);
	step = get_steps(p1, p2);
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_mlx_pixel_put(data, p1.x + (WIDTH / 4), p1.y + (HEIGHT / 4),
			data->color);
		p1.x += step.x;
		p1.y += step.y;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham((t_point){x, y}, (t_point){x + 1, y}, data);
			if (y < data->height - 1)
				bresenham((t_point){x, y}, (t_point){x, y + 1}, data);
			x++;
		}
		y++;
	}
}
