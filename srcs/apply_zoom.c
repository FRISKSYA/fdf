/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:33:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/06 16:15:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}
