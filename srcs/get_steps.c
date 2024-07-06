/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:33:01 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/06 15:35:28 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	get_steps(t_point p1, t_point p2)
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
