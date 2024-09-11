/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:03:12 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/11 23:17:24 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

# define ROOM 0
# define MAZE 1
# define CHAR_MONSTER 'A'
# define CHAR_DOOR 'C'

# define DEFAULT_MODE 0
# define DEFAULT_WIDTH 10
# define DEFAULT_HEIGHT 10
# define DEFAULT_DENSITY 30
# define DEFAULT_NB_MONSTER 0
# define DEFAULT_NB_DOOR 0

# define MAX_WIDTH 1000
# define MIN_WIDTH 10
# define MAX_HEIGHT 1000
# define MIN_HEIGHT 10
# define MAX_DENSITY 100
# define MIN_DENSITY 0
# define MAX_NB_MONSTER 500
# define MIN_NB_MONSTER 0
# define MAX_NB_DOOR 500
# define MIN_NB_DOOR 0

typedef struct s_room
{
	int				x;
	int				y;
	int				width;
	int				height;
	int				center_x;
	int				center_y;
	struct s_room	*next;

}					t_room;

typedef struct s_data
{
	int				mode;
	int				width;
	int				height;
	int				density;
	int				nb_door;
	int				nb_monster;
	char			**map;
	t_room			*room;
}					t_data;

t_room				*create_room(int x, int y, int width, int height);
void				add_back_room(t_room **room, t_room *new);
void				delete_room(t_room **room);
void				clear_rooms(t_room **room);
void				print_rooms(t_data *data);

void				room(t_data *data);
void				maze(t_data *data);
void				add_player(t_data *data);
void				add_monster(t_data *data);
void				add_door(t_data *data);

bool				parse(int argc, char **argv, t_data *data);
void				init_data(t_data *data);
void				close(t_data *data);
bool				place_is_valid_for_player(t_data *data, int x, int y);
bool				room_is_empty(t_data *data, t_room room);
void				fill_with_wall(t_data *data);
void				print_map(t_data *data);
void				close_border(t_data *data);

#endif