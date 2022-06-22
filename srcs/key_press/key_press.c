/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 09:51:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The key_press.c file is where we :
	- make the player moving depending on the key pressed by the user.
	- render the mini_map, updating the new position of the player.
*/

#include "main.h"

static void	change_player_orientation(t_data *data, t_player *player);

int	key_press(int key, t_data *data)
{
	if (key == W)
		move_up(data);
	else if (key == S)
		move_down(data);
	else if (key == A)
		move_left(data);
	else if (key == D)
		move_right(data);
	else if (key == ESC)
		close_window(data);
	if (key == left_arrow)
		turn_left(&data->player);
	if (key == right_arrow)
		turn_right(&data->player);
	change_player_orientation(data, &data->player);
	render_manager(data, &data->win);
	return (0);
}

static void	change_player_orientation(t_data *data, t_player *player)
{
	if ((data->player.rot_angle >= ((7 * M_PI) / 4)
			&& data->player.rot_angle < (2 * M_PI))
		|| (data->player.rot_angle >= 0
			&& data->player.rot_angle < (M_PI / 4)))
		player->orientation = 'E';
	else if (data->player.rot_angle >= (M_PI / 4)
		&& data->player.rot_angle < ((3 * M_PI) / 4))
		player->orientation = 'S';
	else if (data->player.rot_angle >= ((3 * M_PI) / 4)
		&& data->player.rot_angle < ((5 * M_PI) / 4))
		player->orientation = 'W';
	else if (data->player.rot_angle >= ((5 * M_PI) / 4)
		&& data->player.rot_angle < ((7 * M_PI) / 4))
		player->orientation = 'N';
}
