/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:51:57 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:25:52 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

t_room	*create_room(int x, int y, int width, int height)
{
	t_room	*room;

	room = malloc(sizeof(t_room));
	room->x = x;
	room->y = y;
	room->width = width;
	room->height = height;
	room->center_x = x + width / 2;
	room->center_y = y + height / 2;
	room->next = NULL;
	return (room);
}

void	add_back_room(t_room **room, t_room *new)
{
	t_room	*tmp;

	if (!*room)
	{
		*room = new;
		return ;
	}
	tmp = *room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	delete_room(t_room **room)
{
	t_room	*tmp;

	while (*room)
	{
		tmp = *room;
		*room = (*room)->next;
		free(tmp);
	}
}

void	clear_rooms(t_room **room)
{
	t_room	*tmp;

	while (*room)
	{
		tmp = *room;
		*room = (*room)->next;
		free(tmp);
	}
}

void	print_rooms(t_data *data)
{
	t_room	*tmp;

	tmp = data->room;
	while (tmp)
	{
		tmp = tmp->next;
	}
}
