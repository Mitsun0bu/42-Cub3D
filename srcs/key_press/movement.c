/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:30:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 15:18:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_up(t_data *data)
{
	double	move_step;

	data->player.walk_direction = 1;
	move_step = data->player.walk_direction * data->player.move_speed;
	update_player_position(data, move_step, 1);
}

void	move_down(t_data *data)
{
	double	move_step;

	data->player.walk_direction = -1;
	move_step = data->player.walk_direction * data->player.move_speed;
	update_player_position(data, move_step, 1);
}

void	move_left(t_data *data)
{
	double	move_step;

	data->player.walk_direction = 1;
	move_step = data->player.walk_direction * data->player.move_speed;
	update_player_position(data, move_step, 2);
}

void	move_right(t_data *data)
{
	double	move_step;

	data->player.walk_direction = -1;
	move_step = data->player.walk_direction * data->player.move_speed;
	update_player_position(data, move_step, 2);
}

void	update_player_position(t_data *data, double move_step, int dir)
{
	double	new_player_x;
	double	new_player_y;
	double	test_x;
	double	test_y;

	new_player_x = data->player.x;
	new_player_y = data->player.y;
	test_x = data->player.x;
	test_y = data->player.y;
	if (dir == 1)
	{
		new_player_x += cos(data->player.rot_angle) * move_step;
		new_player_y += sin(data->player.rot_angle) * move_step;
		test_x += cos(data->player.rot_angle) * (data->player.walk_direction * (data->player.move_speed + 55));
		test_y += sin(data->player.rot_angle) * (data->player.walk_direction * (data->player.move_speed + 55));
	}
	else
	{
		new_player_x += cos(data->player.rot_angle - M_PI / 2) * move_step;
		new_player_y += sin(data->player.rot_angle - M_PI / 2) * move_step;
		test_x += cos(data->player.rot_angle - M_PI / 2) * (data->player.walk_direction * (data->player.move_speed + 50));
		test_y += sin(data->player.rot_angle - M_PI / 2) * (data->player.walk_direction * (data->player.move_speed + 50));
	}
	if (check_collision(data, test_x, test_y) == FAILED)
	{
		data->player.x = new_player_x;
		data->player.y = new_player_y;
	}
}
