/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:31:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 18:50:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	turn_left(t_player *player)
{
	player->turn_direction = -1;
	player->rot_angle += player->turn_direction * player->rotation_speed;
	player->rot_angle = normalize_angle(player->rot_angle);
}

void	turn_right(t_player *player)
{
	player->turn_direction = 1;
	player->rot_angle += player->turn_direction * player->rotation_speed;
	player->rot_angle = normalize_angle(player->rot_angle);
}
