/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:01:48 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 15:06:33 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

static void	single_room_placement(t_data *data)
{
	t_room	room;
	int		i;
	int		j;

	room.width = rand() % (data->width / 2 + 1);
	room.height = rand() % (data->height / 2 + 1);
	room.x = rand() % (data->width - room.width);
	room.y = rand() % (data->height - room.height);
	if (room_is_empty(data, room) == true)
	{
		add_back_room(&data->room, create_room(room.x, room.y, room.width,
				room.height));
		i = room.y;
		while (i < room.y + room.height)
		{
			j = room.x;
			while (j < room.x + room.width)
			{
				data->map[i][j] = '0';
				j++;
			}
			i++;
		}
	}
}

static void	room_placement(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->density / 5)
	{
		single_room_placement(data);
		i++;
	}
}

static void	add_walkway(t_data *data, t_room *room)
{
	int	i;
	int	j;

	if (rand() % 2 == 0)
	{
		i = 0;
		j = room->center_x;
		while (i < data->height)
		{
			data->map[i][j] = '0';
			i++;
		}
	}
	else
	{
		j = 0;
		i = room->center_y;
		while (j < data->width)
		{
			data->map[i][j] = '0';
			j++;
		}
	}
}

static void	link_room(t_data *data)
{
	t_room	*tmp;

	tmp = data->room;
	while (tmp)
	{
		add_walkway(data, tmp);
		tmp = tmp->next;
	}
}

void	room(t_data *data)
{
	fill_with_wall(data);
	room_placement(data);
	link_room(data);
}
