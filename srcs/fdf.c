/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:53:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/24 13:33:06 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, void *data)
{
	(void)data;
	ft_printf("%d", key);
	return (0);
}

int	close_by_esc(int key, t_fdf *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (EXIT_SUCCESS);
	}
	else
		return (0);
}

//int	main(int argc, char **argv)
//{
//	t_fdf	*data;
//	int	i;
//	int	j;
//
//	data = (t_fdf *)malloc(sizeof(t_fdf));
//	read_file(argv[1], data);
//	i = 0;
//	while (i < data->height)
//	{
//		j = 0;
//		while (j < data->width)
//		{
//			ft_printf(" %d ", data->z_matrix[i][j]);
//			j++;
//		}
//		ft_printf("\n");
//		i++;
//	}
//}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void)argc;
	(void)argv;
	data = (t_fdf *)malloc(sizeof(t_fdf));
//	read_file(argv[1], data);
//	int		i;
//	int		j;
//
//	i = 0;
//	while (i < data->height)
//	{
//		j = 0;
//		while (j < data->width)
//		{
//			ft_printf("%d ", data->z_matrix[i][j]);
//			j++;
//		}
//		ft_printf("\n");
//		i++;
//	}
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1000, 1000, "FDF");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr(
			data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian
			);
	bresenham(10, 600, 10, 300, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L<<0, close_by_esc, data);
	mlx_loop(data->mlx);
}
