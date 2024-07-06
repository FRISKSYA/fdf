/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:32:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/05 18:35:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

static int	ft_wdcounter(char *line, char sep)
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

static int	end_gnl(int fd, int width)
{
	char	*line;
	int		width_tmp;

	line = get_next_line(fd);
	if (line == NULL)
		return (EOF);
	width_tmp = ft_wdcounter(line, ' ');
	if (width != width_tmp)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	free(line);
	return (EXIT_SUCCESS);
}

int	get_width(char *file_name)
{
	int		width;
	int		width_tmp;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (EXIT_FAILURE);
	width = 0;
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	width_tmp = width;
	free(line);
	while (1)
	{
		if (EOF == end_gnl(fd, width))
			break ;
	}
	close(fd);
	return (width);
}