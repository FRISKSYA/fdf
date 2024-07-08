/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:06:14 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 17:07:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_fdf_file(char *file_name)
{
	while (*file_name)
		file_name++;
	if (*(--file_name) != 'f')
		return (false);
	if (*(--file_name) != 'd')
		return (false);
	if (*(--file_name) != 'f')
		return (false);
	if (*(--file_name) != '.')
		return (false);
	return (true);
}

void	init_data(t_fdf *data, char *file_name)
{
	if (malloc_data(file_name, data) == MALLOC_ERROR)
	{
		perror("MALLOC_ERROR");
		exit(EXIT_FAILURE);
	}
	if (read_file(file_name, data) == READ_ERROR)
	{
		perror("READ_ERROR");
		exit(EXIT_FAILURE);
	}
}

void	init_mlx(t_fdf *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		perror("MLX_INIT");
		exit(EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	if (data->mlx_win == NULL)
	{
		perror("MLX_NEW_WINDOW");
		exit(EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
	{
		perror("MLX_NEW_IMAGE");
		exit(EXIT_FAILURE);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
	{
		perror("MLX_GET_DATA_ADDR");
		exit(EXIT_FAILURE);
	}
}

void	init_position(t_fdf *data)
{
	data->shift_x = WIDTH / 5;
	data->shift_y = HEIGHT / 5;
	data->zoom = ZOOM_BASE;
}
