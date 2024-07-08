/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:32:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 16:03:47 by kfukuhar         ###   ########.fr       */
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
	{
		perror("READ_ERROR");
		exit (EXIT_FAILURE);
	}
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
	int	in_wd;

	if (line == NULL)
		return (-1);
	i = 0;
	in_wd = 0;
	while (*line)
	{
		if (*line == sep)
			in_wd = 0;
		else if (in_wd == 0 && *line != sep && *line != '\n')
		{
			in_wd = 1;
			i++;
		}
		line++;
	}
	return (i);
}

// TODO: fix bug has space EOL
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
		perror("MAP_WIDTH_ERROR");
		exit(EXIT_FAILURE);
	}
	free(line);
	return (EXIT_SUCCESS);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		perror("READ_ERROR");
		exit (EXIT_FAILURE);
	}
	width = 0;
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	while (1)
	{
		if (EOF == end_gnl(fd, width))
			break ;
	}
	close(fd);
	return (width);
}
