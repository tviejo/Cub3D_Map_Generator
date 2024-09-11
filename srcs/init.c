/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:43:15 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 15:07:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

void	init_data(t_data *data)
{
	srand(time(NULL));
	data->mode = DEFAULT_MODE;
	data->width = DEFAULT_WIDTH;
	data->height = DEFAULT_HEIGHT;
	data->density = DEFAULT_DENSITY;
	data->nb_door = DEFAULT_NB_DOOR;
	data->nb_monster = DEFAULT_NB_MONSTER;
	data->map = NULL;
	data->room = NULL;
}
