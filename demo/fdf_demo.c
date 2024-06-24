/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_demo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:39:44 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/24 12:01:21 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//// TEST: mlx_new_window()
// int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);
//	return (0);
//}

//// TEST: mlx_new_image()
// int	main(void)
//{
//	void	*img;
//	void	*mlx;
//
//	mlx = mlx_init();
//	img = mlx_new_image(mlx, 1920, 1080);
//	return (0);
//}
// int	main(void)
//{
//	void	*mlx;
//	t_data	img;
//
//	mlx = mlx_init();
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(
//			img.img,
//			&img.bits_per_pixel,
//			&img.line_length,
//			&img.endian
//			);
//}

//// TEST: draw rectangle
// int	main(void)
//{
//	void			*mlx;
//	void			*mlx_win;
//	unsigned int	cols;
//	unsigned int	rows;
//	unsigned int	x;
//	unsigned int	y;
//	t_data			img;
//
//	mlx = mlx_init();
//	cols = 1080;
//	rows = 1080;
//	mlx_win = mlx_new_window(mlx, cols, rows, "Hello world!");
//	img.img = mlx_new_image(mlx, cols, rows);
//	img.addr = mlx_get_data_addr(
//			img.img,
//			&img.bits_per_pixel,
//			&img.line_length,
//			&img.endian
//			);
//	// DRAW: row 0
//	x = cols / 4;
//	y = rows / 4;
//	while (x < cols - (cols / 4))
//	{
//		x += 1;
//		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
//	}
//	// DRAW: col 0
//	x = cols / 4;
//	y = rows / 4;
//	while (y < rows - (rows / 4))
//	{
//		y += 1;
//		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
//	}
//	// DRAW: row 1
//	x = cols / 4;
//	y = rows - (rows / 4);
//	while (x < cols - (cols / 4))
//	{
//		x += 1;
//		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
//	}
//	// DRAW: col 1
//	x = cols - (cols / 4);
//	y = rows / 4;
//	while (y < rows - (rows / 4))
//	{
//		y += 1;
//		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
//	}
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}

//// TEST: draw circle
//void	draw_circle(t_data *img, int center_x, int center_y, int radius,
//		int color)
//{
//	int	x;
//	int	y;
//	int	p;
//	int	deltaE;
//	int	deltaSE;
//
//	x = radius;
//	y = 0;
//	p = 1 - radius;
//	deltaE = 3;
//	deltaSE = 5 - 2 * radius;
//	while (x >= y)
//	{
//		my_mlx_pixel_put(img, center_x + x, center_y + y, color);
//		my_mlx_pixel_put(img, center_x - x, center_y + y, color);
//		my_mlx_pixel_put(img, center_x + x, center_y - y, color);
//		my_mlx_pixel_put(img, center_x - x, center_y - y, color);
//		my_mlx_pixel_put(img, center_x + y, center_y + x, color);
//		my_mlx_pixel_put(img, center_x - y, center_y + x, color);
//		my_mlx_pixel_put(img, center_x + y, center_y - x, color);
//		my_mlx_pixel_put(img, center_x - y, center_y - x, color);
//		y++;
//		if (p <= 0)
//		{
//			p += deltaE;
//			deltaE += 2;
//			deltaSE += 2;
//		}
//		else
//		{
//			x--;
//			p += deltaSE;
//			deltaE += 2;
//			deltaSE += 4;
//		}
//	}
//}
//
//int	main(void)
//{
//	void			*mlx;
//	void			*mlx_win;
//	unsigned int	cols;
//	unsigned int	rows;
//	t_data			img;
//	int				center_x;
//	int				center_y;
//	int				radius;
//	int				color;
//
//	mlx = mlx_init();
//	cols = 900;
//	rows = 900;
//	mlx_win = mlx_new_window(mlx, cols, rows, "Hello world!");
//	img.img = mlx_new_image(mlx, cols, rows);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//			&img.endian);
//	center_x = cols / 2;
//	center_y = rows / 2;
//	radius = cols / 4;
//	color = 0x00FFFF00;
//	draw_circle(&img, center_x, center_y, radius, color);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}

//// TEST: keydown hook
//void	draw_circle(t_data *img, int center_x, int center_y, int radius,
//		int color)
//{
//	int	x;
//	int	y;
//	int	p;
//	int	deltaE;
//	int	deltaSE;
//
//	x = radius;
//	y = 0;
//	p = 1 - radius;
//	deltaE = 3;
//	deltaSE = 5 - 2 * radius;
//	while (x >= y)
//	{
//		my_mlx_pixel_put(img, center_x + x, center_y + y, color);
//		my_mlx_pixel_put(img, center_x - x, center_y + y, color);
//		my_mlx_pixel_put(img, center_x + x, center_y - y, color);
//		my_mlx_pixel_put(img, center_x - x, center_y - y, color);
//		my_mlx_pixel_put(img, center_x + y, center_y + x, color);
//		my_mlx_pixel_put(img, center_x - y, center_y + x, color);
//		my_mlx_pixel_put(img, center_x + y, center_y - x, color);
//		my_mlx_pixel_put(img, center_x - y, center_y - x, color);
//		y++;
//		if (p <= 0)
//		{
//			p += deltaE;
//			deltaE += 2;
//			deltaSE += 2;
//		}
//		else
//		{
//			x--;
//			p += deltaSE;
//			deltaE += 2;
//			deltaSE += 4;
//		}
//	}
//}
//
//int	win_close(int keycode, t_vars *vars)
//{
//	(void)keycode;
//	mlx_destroy_window(vars->mlx, vars->win);
//	exit (1);
//}
//
//int	main(void)
//{
//	t_vars			vars;
//	unsigned int	cols;
//	unsigned int	rows;
//	t_data			img;
//	int				center_x;
//	int				center_y;
//	int				radius;
//	int				color;
//
//	vars.mlx = mlx_init();
//	if (vars.mlx == NULL)
//		exit (1);
//	cols = 900;
//	rows = 900;
//	vars.win = mlx_new_window(vars.mlx, cols, rows, "Hello world!");
//	if (vars.win == NULL)
//		exit (1);
//	img.img = mlx_new_image(vars.mlx, cols, rows);
//	if (img.img == NULL)
//		exit (1);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//			&img.endian);
//	if (img.addr == NULL)
//		exit (1);
//	center_x = cols / 2;
//	center_y = rows / 2;
//	radius = cols / 4;
//	color = 0x00FFFF00;
//	draw_circle(&img, center_x, center_y, radius, color);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, win_close, &vars);
//	mlx_loop(vars.mlx);
//	//return (0);
//}

//int	key_hook(int keycode, t_vars *vars)
//{
//	(void)vars;
//	ft_printf("Hello, num is %d\n", keycode);
//	if (keycode == 53)
//		exit (1);
//	return (0);
//}
//
//int	mouse_hook(int mousecode, t_vars *vars)
//{
//	(void)vars;
//	ft_printf("Hello, num is %d\n", mousecode);
//	if (mousecode == 3)
//		exit (1);
//	return (0);
//}
//
//int	main(void)
//{
//	t_vars	vars;
//
//	vars.mlx = mlx_init();
//	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_mouse_hook(vars.win, mouse_hook, &vars);
//	//mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, win_close, &vars);
//	mlx_loop(vars.mlx);
//}

//// TEST: xpm
//int	main(void)
//{
//	void	*mlx;
//	void	*img;
//	char	*relative_path = "./rockman.xpm";
//	int		img_width;
//	int		img_height;
//
//	mlx = mlx_init();
//	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
//	exit (1);
//}
