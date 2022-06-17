/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 17:58:27 by llethuil         ###   ########lyon.fr   */
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
	change_player_orientation(data, &data->player);
	render_manager(data);
	return (0);
}

void	move_up(t_data *data)
{
	data->player.walk_direction = 1;

	// Determine the quantity of movement of the player in a given direction
	double	move_step;
	move_step = data->player.walk_direction * data->player.move_speed;

	// Update player position, only if no wall is encountered
	update_player_position(data, move_step);
}

void	move_down(t_data *data)
{
	data->player.walk_direction = -1;

	// Determine the quantity of movement of the player in a given direction
	double	move_step;
	move_step = data->player.walk_direction * data->player.move_speed;

	// Update player position, only if no wall is encountered
	update_player_position(data, move_step);
}

void	move_left(t_data *data)
{
	(void)data;
	// data->player.turn_direction = -1;
	// data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
}

void	move_right(t_data *data)
{
	(void)data;
	// data->player.turn_direction = 1;
	// data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
}

void	turn_left(t_data *data)
{
	data->player.turn_direction = -1;
	data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
	data->player.rotation_angle = normalize_angle(data->player.rotation_angle);
}

void	turn_right(t_data *data)
{
	data->player.turn_direction = 1;
	data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
	data->player.rotation_angle = normalize_angle(data->player.rotation_angle);
}

void	update_player_position(t_data *data, double move_step)
{
	double	new_player_x;
	double	new_player_y;

	new_player_x = data->player.x;
	new_player_y = data->player.y;
	new_player_x += cos(data->player.rotation_angle) * move_step;
	new_player_y += sin(data->player.rotation_angle) * move_step;
	// If no wall only, update player position
	if (check_collision(data, new_player_x, new_player_y) == FAILED)
	{
		data->player.x = new_player_x;
		data->player.y = new_player_y;
	}
}

int		check_collision(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x > data->win.wdth || y < 0 || y > data->win.hgt)
		return (SUCCESS);
	map_x = floor(x / data->map.cell_size);
	map_y = floor(y / data->map.cell_size);

	if (data->map.tab[map_y][map_x] == '1')
		return (SUCCESS);
	return (FAILED);
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