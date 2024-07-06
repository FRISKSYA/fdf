/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:53:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/05 19:30:43 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	init_data(t_fdf	*data, char *file_name)
{
	if (malloc_data(file_name, data) == MALLOC_ERROR)
		exit(EXIT_FAILURE);
	if (read_file(file_name, data) == READ_ERROR)
		exit(EXIT_FAILURE);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(
			data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian
			);
	data->zoom = ZOOM_BASE;
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		exit (EXIT_SUCCESS);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
		exit (EXIT_FAILURE);
	init_data(data, argv[1]);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L << 0, close_by_esc, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 1L << 17, exit_program, data);
	mlx_loop(data->mlx);
}
