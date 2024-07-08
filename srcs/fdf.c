/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:53:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 17:13:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ctl_mlx(t_fdf *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L << 0, close_by_esc, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 1L << 17, exit_program, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		perror("ARGC_ERROR");
		exit(EXIT_FAILURE);
	}
	if (is_fdf_file(argv[1]) == false)
	{
		perror("FILE_NAME_ERROR");
		exit(EXIT_FAILURE);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
	{
		perror("MALLOC_ERROR");
		exit(EXIT_FAILURE);
	}
	init_data(data, argv[1]);
	init_mlx(data);
	init_position(data);
	draw(data);
	ctl_mlx(data);
}
