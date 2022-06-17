/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_probe_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:41:34 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 12:43:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_v_probe(t_map *map, t_player *player, double ray_angle, t_dda_ray *v_probe)
{
	v_probe->orientation = get_ray_orientation(player, ray_angle);
	v_probe->wall_hit_x = 0;
	v_probe->wall_hit_y = 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	v_probe->x_intercept = floor(player->x / map->cell_size) * map->cell_size;
	v_probe->x_intercept += (v_probe->orientation == NE || v_probe->orientation == SE) ? map->cell_size : 0;

	// Find the y-coordinate of the closest horizontal grid intersection
	v_probe->y_intercept = player->y + (v_probe->x_intercept - player->x) * tan(ray_angle);

	// Calculate the increment x_step and y_step
	v_probe->x_step = map->cell_size;
	v_probe->x_step *= (v_probe->orientation == NW || v_probe->orientation == SW) ? -1 : 1;

	v_probe->y_step = map->cell_size * tan(ray_angle);
	v_probe->y_step *= ((v_probe->orientation == NW || v_probe->orientation == NE) && v_probe->y_step > 0) ? -1 : 1;
	v_probe->y_step *= ((v_probe->orientation == SW || v_probe->orientation == SE) && v_probe->y_step < 0) ? -1 : 1;

	v_probe->next_touch_x = v_probe->x_intercept;
	v_probe->next_touch_y = v_probe->y_intercept;
	v_probe->horizontal_wall_hit = 0;
	v_probe->vertical_wall_hit = 0;
}

void	find_v_probe_wall_hit(t_data *data, t_win *win, t_dda_ray *v_probe)
{
	float	x_to_check;
	float	y_to_check;

	// Increment x_step and y_step until we find a wall
	while (v_probe->next_touch_x >= 0 && v_probe->next_touch_x <= win->wdth && v_probe->next_touch_y >= 0 && v_probe->next_touch_y <= win->hgt)
	{
		x_to_check = v_probe->next_touch_x - ((v_probe->orientation == NW || v_probe->orientation == SW) ? 1 : 0);
		y_to_check = v_probe->next_touch_y;

		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			v_probe->wall_hit_x = v_probe->next_touch_x;
			v_probe->wall_hit_y = v_probe->next_touch_y;
			v_probe->horizontal_wall_hit = 0;
			v_probe->vertical_wall_hit = 1;
			v_probe->grid_hit = HORIZONTAL;
			break;
		}
		else
		{
			v_probe->next_touch_x += v_probe->x_step;
			v_probe->next_touch_y += v_probe->y_step;
		}
	}
}
