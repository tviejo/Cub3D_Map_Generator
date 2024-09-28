/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:38:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/28 17:02:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

static char	*find_next_file(t_data *data)
{
	int		i;
	char	*buffer;

	buffer = malloc(100);
	i = 0;
	while (1)
	{
		sprintf(buffer, "Cub_%d_by_%d_%d.cub", data->width, data->height, i);
		if (access(buffer, F_OK) == -1)
			return (buffer);
		i++;
	}
}

static void	write_map_file(t_data *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			write(fd, &data->map[i][j], 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

static void	write_texture_file(int fd)
{
	write(fd, "NO ", 3);
	write(fd, TEXT_NORTH, strlen(TEXT_NORTH));
	write(fd, "\n", 1);
	write(fd, "SO ", 3);
	write(fd, TEXT_SOUTH, strlen(TEXT_SOUTH));
	write(fd, "\n", 1);
	write(fd, "WE ", 3);
	write(fd, TEXT_WEST, strlen(TEXT_WEST));
	write(fd, "\n", 1);
	write(fd, "EA ", 3);
	write(fd, TEXT_EAST, strlen(TEXT_EAST));
	write(fd, "\n", 1);
}

static void	write_color_file(int fd)
{
	char	buffer[100];

	sprintf(buffer, "F %d,%d,%d\n", COLOR_FLOOR);
	write(fd, buffer, strlen(buffer));
	sprintf(buffer, "C %d,%d,%d\n", COLOR_CEILING);
	write(fd, buffer, strlen(buffer));
}

void	create_file(t_data *data)
{
	int		fd;
	char	*str;

	str = find_next_file(data);
	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(str);
	if (fd == -1)
	{
		printf("Error\n");
		exit(1);
	}
	write_texture_file(fd);
	write(fd, "\n", 1);
	write_color_file(fd);
	write(fd, "\n", 1);
	write_map_file(data, fd);
	close(fd);
}
