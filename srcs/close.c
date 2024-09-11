/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:11:24 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:59:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

static void	free_map(t_data *data)
{
	int	i;

	if (data->map == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	close(t_data *data)
{
	free_map(data);
	clear_rooms(&data->room);
}
