/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:36:35 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 14:53:44 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_generator.h"

static void	print_usage(void)
{
	printf("Usage: ./map_generator [mode] [width] [height] [density]");
	printf(" [nb_monster] [nb_door]\n");
	printf("mode: 0 for room, 1 for maze\n");
	printf("width: width of the map\n");
	printf("height: height of the map\n");
	printf("density: density of the map\n");
	printf("nb_monster: number of monsters\n");
	printf("nb_door: number of doors\n");
	printf("Example: ./map_generator 0 50 50 40 5 5\n\n");
	printf("if a value is not set it will be set to default value\n\n");
	printf("default values:\n");
	if (DEFAULT_MODE == ROOM)
		printf("mode: 0 (room)\n");
	else
		printf("mode: 1 (maze)\n");
	printf("width: %d\n", DEFAULT_WIDTH);
	printf("height: %d\n", DEFAULT_HEIGHT);
	printf("density: %d\n", DEFAULT_DENSITY);
	printf("nb_monster: %d\n", DEFAULT_NB_MONSTER);
	printf("nb_door: %d\n\n", DEFAULT_NB_DOOR);
}

static void	parse_arg(int argc, char **argv, t_data *data)
{
	init_data(data);
	if (argc == 1)
		print_usage();
	if (argc >= 2)
		data->mode = atoi(argv[1]);
	if (argc >= 3)
		data->width = atoi(argv[2]);
	if (argc >= 4)
		data->height = atoi(argv[3]);
	if (argc >= 5)
		data->density = atoi(argv[4]);
	if (argc >= 6)
		data->nb_monster = atoi(argv[5]);
	if (argc >= 7)
		data->nb_door = atoi(argv[6]);
}

static bool	check_data_2(t_data *data)
{
	if (data->nb_monster < MIN_NB_MONSTER || data->nb_monster > MAX_NB_MONSTER)
	{
		printf("Error: nb_monster must be between %d and %d\n", MIN_NB_MONSTER,
			MAX_NB_MONSTER);
		return (false);
	}
	if (data->nb_door < MIN_NB_DOOR || data->nb_door > MAX_NB_DOOR)
	{
		printf("Error: nb_door must be between %d and %d\n", MIN_NB_DOOR,
			MAX_NB_DOOR);
		return (false);
	}
	return (true);
}

static bool	check_data(t_data *data)
{
	if (data->mode != ROOM && data->mode != MAZE)
	{
		printf("Error: mode must be 0 or 1\n");
		return (false);
	}
	if (data->width < MIN_WIDTH || data->width > MAX_WIDTH)
	{
		printf("Error: width must be between %d and %d\n", MIN_WIDTH,
			MAX_WIDTH);
		return (false);
	}
	if (data->height < MIN_HEIGHT || data->height > MAX_HEIGHT)
	{
		printf("Error: height must be between %d and %d\n", MIN_HEIGHT,
			MAX_HEIGHT);
		return (false);
	}
	if (data->density < MIN_DENSITY || data->density > MAX_DENSITY)
	{
		printf("Error: density must be between %d and %d\n", MIN_DENSITY,
			MAX_DENSITY);
		return (false);
	}
	return (check_data_2(data));
}

bool	parse(int argc, char **argv, t_data *data)
{
	bool	ret;

	if (argc > 7)
	{
		printf("Error: too many arguments\n");
		return (false);
	}
	parse_arg(argc, argv, data);
	ret = check_data(data);
	return (ret);
}
