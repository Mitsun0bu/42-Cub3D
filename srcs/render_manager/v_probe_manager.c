/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_probe_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:11:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 12:03:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_v_probe(t_player *player, double angle, t_probe *probe)
{
	int	no_oriented;
	int	so_oriented;

	probe->orientation = get_ray_orientation(player, angle);
	probe->wall_hit_x = 0;
	probe->wall_hit_y = 0;
	no_oriented = (probe->orientation == NW || probe->orientation == NE);
	so_oriented = (probe->orientation == SW || probe->orientation == SE);
	probe->x_intcp = floor(player->x / CELL_SIZE) * CELL_SIZE;
	if (probe->orientation == NE || probe->orientation == SE)
		probe->x_intcp += CELL_SIZE;
	probe->y_intcp = player->y + (probe->x_intcp - player->x) * tan(angle);
	probe->x_step = CELL_SIZE;
	if (probe->orientation == NW || probe->orientation == SW)
		probe->x_step *= -1;
	probe->y_step = CELL_SIZE * tan(angle);
	if (no_oriented && probe->y_step > 0)
		probe->y_step *= -1;
	if (so_oriented && probe->y_step < 0)
		probe->y_step *= -1;
	probe->next_touch_x = probe->x_intcp;
	probe->next_touch_y = probe->y_intcp;
	probe->horizontal_wall_hit = 0;
	probe->vertical_wall_hit = 0;
}

void	find_v_probe_wall_hit(t_data *data, t_map *map, t_probe *probe)
{
	float	x_to_check;
	float	y_to_check;

	while (probe->next_touch_x >= 0 && probe->next_touch_x <= map->wdth * CELL_SIZE
		&& probe->next_touch_y >= 0 && probe->next_touch_y <= map->hgt * CELL_SIZE)
	{
		x_to_check = probe->next_touch_x;
		y_to_check = probe->next_touch_y;
		if (probe->orientation == NW || probe->orientation == SW)
			x_to_check += -1;
		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			probe->wall_hit_x = probe->next_touch_x;
			probe->wall_hit_y = probe->next_touch_y;
			probe->horizontal_wall_hit = 0;
			probe->vertical_wall_hit = 1;
			probe->grid_hit = HORIZONTAL;
			break ;
		}
		else
		{
			probe->next_touch_x += probe->x_step;
			probe->next_touch_y += probe->y_step;
		}
	}
}
