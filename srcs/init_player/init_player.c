/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:25:28 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 14:31:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The init_player.c file is where we initialize the direction vector.
	The x and y coordinates and the angle depend on player_orientation.
	player_orientation is found in config struct but is passed
	as a char argument to the function init_player.
*/

#include "main.h"

static void	init_player_dir(t_player *player, t_config *config);

void	init_player(t_player *player, t_config *config)
{
	player->x = (player->x * CELL_SIZE) + (CELL_SIZE / 2);
	player->y = player->y * CELL_SIZE + (CELL_SIZE / 2);
	player->radius = 3;
	init_player_dir(player, config);
	player->move_speed = 8.0;
	player->rotation_speed = 4 * (M_PI / 180);
	player->fov = 60 * (M_PI / 180);
}

static void	init_player_dir(t_player *player, t_config *config)
{
	if (config->player_orientation == 'N')
	{
		player->walk_direction = 1;
		player->rot_angle = (3 * M_PI) / 2;
	}
	else if (config->player_orientation == 'S')
	{
		player->walk_direction = -1;
		player->rot_angle = M_PI / 2;
	}
	else if (config->player_orientation == 'W')
	{
		player->turn_direction = -1;
		player->rot_angle = M_PI;
	}
	else if (config->player_orientation == 'E')
	{
		player->turn_direction = 1;
		player->rot_angle = 2 * M_PI;
	}
}
