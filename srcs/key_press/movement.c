/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:30:47 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 16:18:25 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_up(t_data *data)
{
	double	move_step;

	data->player.walk_dir = 1;
	move_step = data->player.walk_dir * data->player.move_speed;
	update_up_down_pos(data, &data->player, move_step);
}

void	move_down(t_data *data)
{
	double	move_step;

	data->player.walk_dir = -1;
	move_step = data->player.walk_dir * data->player.move_speed;
	update_up_down_pos(data, &data->player, move_step);
}

void	move_left(t_data *data)
{
	double	move_step;

	data->player.walk_dir = 1;
	move_step = data->player.walk_dir * data->player.move_speed;
	update_left_right_pos(data, &data->player, move_step);
}

void	move_right(t_data *data)
{
	double	move_step;

	data->player.walk_dir = -1;
	move_step = data->player.walk_dir * data->player.move_speed;
	update_left_right_pos(data, &data->player, move_step);
}
