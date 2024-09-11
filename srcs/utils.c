/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:48:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:49:30 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	close_border(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		data->map[0][i] = '1';
		data->map[data->height - 1][i] = '1';
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		data->map[i][0] = '1';
		data->map[i][data->width - 1] = '1';
		i++;
	}
}
