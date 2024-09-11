/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:07:26 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:24:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

bool	room_is_empty(t_data *data, t_room room)
{
	int	i;
	int	j;

	if (room.y + room.height < data->height)
		room.height++;
	if (room.x + room.width < data->width)
		room.width++;
	i = room.y;
	if (i > 0)
		i--;
	while (i < room.y + room.height)
	{
		j = room.x;
		if (j > 0)
			j--;
		while (j < room.x + room.width)
		{
			if (data->map[i][j] == '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	fill_with_wall(t_data *data)
{
	int	i;
	int	j;

	data->map = malloc(sizeof(char *) * data->height);
	if (data->map == NULL)
	{
		exit(1);
	}
	i = 0;
	while (i < data->height)
	{
		data->map[i] = malloc(sizeof(char) * data->width);
		if (data->map[i] == NULL)
		{
			exit(1);
		}
		j = 0;
		while (j < data->width)
		{
			data->map[i][j] = '1';
			j++;
		}
		i++;
	}
}
