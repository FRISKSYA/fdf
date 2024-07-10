/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:37:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/10 15:00:33 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_z_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (data->z_matrix[i])
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}

int	close_by_esc(int key, t_fdf *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_image(data->mlx, data->img);
		free_z_matrix(data);
		free(data);
		exit (EXIT_SUCCESS);
	}
	else
		return (0);
}

int	exit_program(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_z_matrix(data);
	free(data);
	exit(EXIT_SUCCESS);
}
