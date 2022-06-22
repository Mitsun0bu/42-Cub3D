/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:16:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 16:26:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	update_up_down_pos(t_data *data, t_player *player, double move_step)
{
	double	new_player_x;
	double	new_player_y;
	double	test_x;
	double	test_y;
	double	move_step_test;

	new_player_x = player->x;
	new_player_y = player->y;
	new_player_x += cos(player->rot_angle) * move_step;
	new_player_y += sin(player->rot_angle) * move_step;
	test_x = player->x;
	test_y = player->y;
	move_step_test = player->walk_dir * (player->move_speed + 55);
	test_x += cos(player->rot_angle) * move_step_test;
	test_y += sin(player->rot_angle) * move_step_test;
	if (check_collision(data, test_x, test_y) == FAILED)
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}

void	update_left_right_pos(t_data *data, t_player *player, double move_step)
{
	double	new_player_x;
	double	new_player_y;
	double	test_x;
	double	test_y;
	double	move_step_test;

	new_player_x = player->x;
	new_player_y = player->y;
	new_player_x += cos(player->rot_angle - M_PI / 2) * move_step;
	new_player_y += sin(player->rot_angle - M_PI / 2) * move_step;
	test_x = player->x;
	test_y = player->y;
	move_step_test = player->walk_dir * (player->move_speed + 50);
	test_x += cos(player->rot_angle - M_PI / 2) * move_step_test;
	test_y += sin(player->rot_angle - M_PI / 2) * move_step_test;
	if (check_collision(data, test_x, test_y) == FAILED)
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}
