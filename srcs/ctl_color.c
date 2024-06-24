/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:33:54 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/23 16:04:41 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	add_shade(double distance, int color)
{
	int		t;
	int		r;
	int		g;
	int		b;
	double	shade_factor;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	shade_factor = 1.0 - distance;
	if (shade_factor < 0.0)
		shade_factor = 0.0;
	r = (int)(r * shade_factor);
	g = (int)(g * shade_factor);
	b = (int)(b * shade_factor);
	return (create_trgb(t, r, g, b));
}

int	get_opposite(int color)
{
	int		t;
	int		r;
	int		g;
	int		b;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	return (
			create_trgb(
				t,
				0xFF - r,
				0xFF - g,
				0xFF - b
				)
			);
}
