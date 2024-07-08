/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:10:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 15:55:30 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fill_matrix(int *z_line, char *line)
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

int	malloc_data(char *file_name, t_fdf *data)
{
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (data->z_matrix == NULL)
		return (MALLOC_ERROR);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (data->z_matrix[i] == NULL)
		{
			free(data->z_matrix);
			return (MALLOC_ERROR);
		}
		i++;
	}
	data->z_matrix[i] = NULL;
	return (SUCCESS);
}

int	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (READ_ERROR);
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
	return (SUCCESS);
}
