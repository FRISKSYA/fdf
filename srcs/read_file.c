/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:10:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/23 17:51:52 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (1);
	height = 0;
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	ft_wdcounter(char *line, char sep)
{
	int	i;
	int	is_in_wd;

	if (line == NULL)
		return (-1);
	i = 0;
	is_in_wd = 0;
	while (*line)
	{
		while (*line && *line == sep)
			line++;
		if (*line != '\0')
			is_in_wd = 1;
		if (is_in_wd == 1)
			i++;
		while (*line && *line != sep)
			line++;
		if (*line != '\0')
			is_in_wd = 0;
	}
	return (i);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (1);
	width = 0;
	line = NULL;
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	while ((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int  *z_line, char *line)
{
	int		i;
	char	**nums;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (1);
	i = 0;
	line = NULL;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
