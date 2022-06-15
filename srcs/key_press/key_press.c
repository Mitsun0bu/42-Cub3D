/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/14 10:54:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The key_press.c file is where we :
	- make the player moving depending on the key pressed by the user.
	- render the mini_map, updating the new position of the player.
*/

#include "main.h"

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
		turn_left(data);
	if (key == right_arrow)
		turn_right(data);
	render_manager(data);
	return (0);
}

void	move_up(t_data *data)
{
	data->player.walk_direction = 1;
}

void	move_down(t_data *data)
{
	data->player.walk_direction = -1;
}

void	move_left(t_data *data)
{
	data->player.walk_direction = -1;
}

void	move_right(t_data *data)
{
	data->player.turn_direction = 1;
}

void	turn_left(t_data *data)
{
	(void)data;
}

void	turn_right(t_data *data)
{
	(void)data;
}

void	change_player_orientation(t_data *data, t_player *player)
{
	if ((data->player.rotation_angle >= ((7 * M_PI) / 4)
			&& data->player.rotation_angle < (2 * M_PI))
		|| (data->player.rotation_angle >= 0
			&& data->player.rotation_angle < (M_PI / 4)))
		player->orientation = 'E';
	else if (data->player.rotation_angle >= (M_PI / 4)
		&& data->player.rotation_angle < ((3 * M_PI) / 4))
		player->orientation = 'S';
	else if (data->player.rotation_angle >= ((3 * M_PI) / 4)
		&& data->player.rotation_angle < ((5 * M_PI) / 4))
		player->orientation = 'W';
	else if (data->player.rotation_angle >= ((5 * M_PI) / 4)
		&& data->player.rotation_angle < ((7 * M_PI) / 4))
		player->orientation = 'N';
}
