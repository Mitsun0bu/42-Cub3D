/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:25 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:35:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The init_player.c file is where we initialize the direction vector.
	The x and y coordinates and the angle depend on player_orientation.
	player_orientation is found in config struct but is passed
	as a char argument to the function init_player.
*/

#include "main.h"

// static void	init_player_dir(t_player *player, t_config *config);
// static void	init_player_cam_plane(t_player *player);

void	init_player(t_data *data, t_player *player, t_config *config)
{
	(void)data;
	(void)config;
	player->x = (player->x * data->map.tile_size) + (data->map.tile_size / 2);
	player->y = player->y * data->map.tile_size + (data->map.tile_size / 2);
	player->radius = 3;
	player->turn_direction = 0; // -1 if left, +1 if right
	player->walk_direction = 0; // -1 if back, +1 if front
	player->rotation_angle = M_PI / 2;
	player->move_speed = 2.0;
	player->rotation_speed = 2 * (M_PI / 180); // 2 deg converted into rad
}

// static void	init_player_dir(t_player *player, t_config *config)
// {
// 	if (config->player_orientation == 'N')
// 	{
// 		player->dir.x = 0;
// 		player->dir.y = 1;
// 		player->dir.angle = (3 * M_PI)/2;
// 	}
// 	else if (config->player_orientation == 'S')
// 	{
// 		player->dir.x = 0;
// 		player->dir.y = -1;
// 		player->dir.angle = M_PI/2;
// 	}
// 	else if (config->player_orientation == 'W')
// 	{
// 		player->dir.x = 1;
// 		player->dir.y = 0;
// 		player->dir.angle = M_PI;
// 	}
// 	else if (config->player_orientation == 'E')
// 	{
// 		player->dir.x = -1;
// 		player->dir.y = 0;
// 		player->dir.angle = 2 * M_PI;
// 	}
// }

// static void	init_player_cam_plane(t_player *player)
// {
// 	player->cam_plane.x = 0;
// 	player->cam_plane.y = 0.66;
// }
