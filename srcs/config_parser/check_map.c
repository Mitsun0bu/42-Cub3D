/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:54 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:32:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The check_map.c file is where we :
	- check that the map contains only allowed characters (0,1,N,S,W, and E).
	- initialize the orientation and position of the player.
	- check that there is (only) one player on the map.
- check that the map is closed, i.e. surrounded by walls ('1' characters).
*/

#include "main.h"

static int	get_player_info(t_data *data, int x, int y);
static int	map_is_closed(t_map *map, int x, int y);
static int	check_vertical_lines(t_map *map, int x, int y);
static int	check_horizontal_lines(t_map *map, int y);

void	check_map(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map.hgt)
	{
		x = -1;
		while (data->map.tab[y][++x])
		{
			if (!ft_strchr("01NSEW", data->map.tab[y][x]))
				exit_with_error_message(map_err, invalid);
			if (ft_strchr("NSEW", data->map.tab[y][x]))
				if (get_player_info(data, x, y) == FAILED)
					exit_with_error_message(map_err, n_player);
			if (data->map.tab[y][x] != '1')
				if (map_is_closed(&data->map, x, y) == NO)
					exit_with_error_message(map_err, walls);
			if (x + 1 > data->map.wdth)
				data->map.wdth = x + 1;
		}
	}
	if (!data->config.player_orientation)
		exit_with_error_message(map_err, n_player);
}

static int	get_player_info(t_data *data, int x, int y)
{
	if (data->config.player_orientation != 0)
		return (FAILED);
	data->config.player_orientation = data->map.tab[y][x];
	data->player.x = x;
	data->player.y = y;
	data->player.orientation = data->config.player_orientation;
	return (SUCCESS);
}

static int	map_is_closed(t_map *map, int x, int y)
{
	if (check_vertical_lines(map, x, y) == FAILED
		|| check_horizontal_lines(map, y) == FAILED)
		return (NO);
	return (YES);
}

static int	check_vertical_lines(t_map *map, int x, int y)
{
	int	wall_found;
	int	i;

	if (y == map->hgt || y == 0)
		return (FAILED);
	wall_found = 0;
	i = y;
	while (i < map->hgt && i != 0)
	{
		if (wall_found == 0)
			i++;
		else
			i--;
		if (!((int)ft_strlen(map->tab[i]) - 1 >= x))
			return (FAILED);
		if (map->tab[i][x] == '1')
			wall_found++;
		if (wall_found == 2)
			return (SUCCESS);
	}
	return (FAILED);
}

static int	check_horizontal_lines(t_map *map, int y)
{
	int	line_size;

	line_size = (int)ft_strlen(map->tab[y]) - 1;
	if (map->tab[y][line_size] != '1' || map->tab[y][0] != '1')
		return (FAILED);
	return (SUCCESS);
}
