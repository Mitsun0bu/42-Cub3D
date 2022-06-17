/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_probe_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:39:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 12:43:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_h_probe(t_map *map, t_player *player, double ray_angle, t_dda_ray *h_probe)
{
	h_probe->orientation = get_ray_orientation(player, ray_angle);

	// Find the y-coordinate of the closest horizontal grid intersection
	h_probe->y_intercept = floor(player->y / map->cell_size) * map->cell_size;
	h_probe->y_intercept += (h_probe->orientation == SW || h_probe->orientation == SE) ? map->cell_size : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	h_probe->x_intercept = player->x + (h_probe->y_intercept - player->y) / tan(ray_angle);

	// Calculate the increment x_step and y_step
	h_probe->y_step = map->cell_size;
	h_probe->y_step *= (h_probe->orientation == NW || h_probe->orientation == NE) ? -1 : 1;

	h_probe->x_step = map->cell_size / tan(ray_angle);
	h_probe->x_step *= ((h_probe->orientation == NW || h_probe->orientation == SW) && h_probe->x_step > 0) ? -1 : 1;
	h_probe->x_step *= ((h_probe->orientation == NE || h_probe->orientation == SE) && h_probe->x_step < 0) ? -1 : 1;

	h_probe->wall_hit_x = 0;
	h_probe->wall_hit_y = 0;
	h_probe->next_touch_x = h_probe->x_intercept;
	h_probe->next_touch_y = h_probe->y_intercept;
	h_probe->hit_found = -1;
}

void	find_h_probe_wall_hit(t_data *data, t_win *win, t_dda_ray *h_probe)
{
	float	x_to_check;
	float	y_to_check;

	// Increment x_step and y_step until we find a wall
	while (h_probe->next_touch_x >= 0 && h_probe->next_touch_x <= win->wdth && h_probe->next_touch_y >= 0 && h_probe->next_touch_y <= win->hgt)
	{
		x_to_check = h_probe->next_touch_x;
		y_to_check = h_probe->next_touch_y + ((h_probe->orientation == NW || h_probe->orientation == NE) ? -1 : 0);

		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			h_probe->wall_hit_x = h_probe->next_touch_x;
			h_probe->wall_hit_y = h_probe->next_touch_y;
			h_probe->hit_found = 1;
			break;
		}
		else
		{
			h_probe->next_touch_x += h_probe->x_step;
			h_probe->next_touch_y += h_probe->y_step;
		}
	}
}