/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:49:56 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/05 17:45:08 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_mod(float f)
{
	if (f < 0)
		return (-f);
	else
		return (f);
}

// NOTE: angle = 1.0 is std isometric
void	isometric(float *x, float *y, int z)
{
	float	angle;

	angle = 1.0;
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}
