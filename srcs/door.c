/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:06:39 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:26:57 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

static bool	door_is_possible(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0')
	{
		if (data->map[y + 1][x] == '0' && data->map[y - 1][x] == '0'
			&& data->map[y][x + 1] == '1' && data->map[y][x - 1] == '1')
			return (true);
		if (data->map[y + 1][x] == '1' && data->map[y - 1][x] == '1'
			&& data->map[y][x + 1] == '0' && data->map[y][x - 1] == '0')
			return (true);
	}
	return (false);
}

void	add_door(t_data *data)
{
	int	nb_door;
	int	i;
	int	x;
	int	y;

	i = 0;
	nb_door = 0;
	while (i < 1000 && nb_door < 5)
	{
		i++;
		x = rand() % (data->width - 3);
		y = rand() % (data->height - 3);
		x += 2;
		y += 2;
		if (door_is_possible(data, x, y))
		{
			data->map[y][x] = CHAR_DOOR;
			nb_door++;
		}
	}
}
