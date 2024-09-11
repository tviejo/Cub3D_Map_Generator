/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:02:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 15:03:42 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

bool	place_is_valid_for_player(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	nb_place;

	nb_place = 0;
	i = y;
	if (i > 1)
		i -= 2;
	while (i < y + 3 && i < data->height)
	{
		j = x;
		if (j > 1)
			j -= 2;
		while (j < x + 3 && j < data->width)
		{
			if (data->map[i][j] == '0')
				nb_place++;
			j++;
		}
		i++;
	}
	if (nb_place >= 9 && data->map[y][x] == '0')
		return (true);
	return (false);
}

void	add_player(t_data *data)
{
	int	i;
	int	j;
	int	mode;
	int	nb;

	nb = 0;
	while (nb++ < 1000)
	{
		i = rand() % data->height;
		j = rand() % data->width;
		if (place_is_valid_for_player(data, j, i) == true)
		{
			mode = rand() % 4;
			if (mode == 0)
				data->map[i][j] = 'N';
			else if (mode == 1)
				data->map[i][j] = 'S';
			else if (mode == 2)
				data->map[i][j] = 'E';
			else
				data->map[i][j] = 'W';
			break ;
		}
	}
}
