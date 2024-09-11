/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:02:18 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:27:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

static int	find_nb_neighbors_close(t_data *data, int i, int j)
{
	int			nb_wall;
	const char	c = data->map[i][j];

	nb_wall = 0;
	if (i > 0 && data->map[i - 1][j] == c)
		nb_wall++;
	if (i < data->height - 1 && data->map[i + 1][j] == c)
		nb_wall++;
	if (j > 0 && data->map[i][j - 1] == c)
		nb_wall++;
	if (j < data->width - 1 && data->map[i][j + 1] == c)
		nb_wall++;
	if (i > 0 && j > 0 && data->map[i - 1][j - 1] == c)
		nb_wall++;
	if (i > 0 && j < data->width - 1 && data->map[i - 1][j + 1] == c)
		nb_wall++;
	if (i < data->height - 1 && j > 0 && data->map[i + 1][j - 1] == c)
		nb_wall++;
	if (i < data->height - 1 && j < data->width - 1 && data->map[i + 1][j
		+ 1] == c)
		nb_wall++;
	return (nb_wall);
}

static void	cellular_automata(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->height - 1)
	{
		j = 1;
		while (j < data->width - 1)
		{
			if (find_nb_neighbors_close(data, i, j) >= 5)
				data->map[i][j] = '1';
			else if (find_nb_neighbors_close(data, i, j) <= 1)
				data->map[i][j] = '1';
			else
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

static void	generate_random_map(t_data *data)
{
	int	i;
	int	j;

	data->map = malloc(sizeof(char *) * data->height);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		data->map[i] = malloc(sizeof(char) * data->width);
		while (j < data->width)
		{
			if (rand() % 100 < data->density)
				data->map[i][j] = '1';
			else
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	maze(t_data *data)
{
	int	i;

	generate_random_map(data);
	i = 0;
	while (i < 5)
	{
		cellular_automata(data);
		i++;
	}
}
