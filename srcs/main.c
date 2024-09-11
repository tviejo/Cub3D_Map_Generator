/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:02:05 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:48:47 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse(argc, argv, &data) == false)
	{
		close(&data);
		return (EXIT_FAILURE);
	}
	if (data.mode == MAZE)
		maze(&data);
	else
		room(&data);
	close_border(&data);
	add_door(&data);
	add_player(&data);
	add_monster(&data);
	print_map(&data);
	close(&data);
	return (EXIT_SUCCESS);
}
