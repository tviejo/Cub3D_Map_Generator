/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:02:47 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:26:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

void	add_monster(t_data *data)
{
	int	i;
	int	j;
	int	nb_monster;
	int	x;

	nb_monster = 0;
	x = 0;
	while (x++ < 1000 && nb_monster < data->nb_monster)
	{
		i = rand() % data->height;
		j = rand() % data->width;
		if (place_is_valid_for_player(data, j, i) == true)
		{
			data->map[i][j] = CHAR_MONSTER;
			nb_monster++;
		}
	}
}
