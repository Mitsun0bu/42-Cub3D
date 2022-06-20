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

void	init_h_probe(t_map *map, t_player *player, double angle, t_probe *probe)
{
	int	we_oriented;
	int	ea_oriented;

	probe->orientation = get_ray_orientation(player, angle);
	probe->wall_hit_x = 0;
	probe->wall_hit_y = 0;
	we_oriented = (probe->orientation == NW || probe->orientation == SW);
	ea_oriented = (probe->orientation == NE || probe->orientation == SE);
	probe->y_intcp = floor(player->y / map->cell_size) * map->cell_size;
	if (probe->orientation == SW || probe->orientation == SE)
		probe->y_intcp += map->cell_size;
	probe->x_intcp = player->x + (probe->y_intcp - player->y) / tan(angle);
	probe->y_step = map->cell_size;
	if (probe->orientation == NW || probe->orientation == NE)
		probe->y_step *= -1;
	probe->x_step = map->cell_size / tan(angle);
	if (we_oriented && probe->x_step > 0)
		probe->x_step *= -1;
	if (ea_oriented && probe->x_step < 0)
		probe->x_step *= -1;
	probe->next_touch_x = probe->x_intcp;
	probe->next_touch_y = probe->y_intcp;
	probe->horizontal_wall_hit = 0;
	probe->vertical_wall_hit = 0;
}

void	find_h_probe_wall_hit(t_data *data, t_win *win, t_probe *probe)
{
	float	x_to_check;
	float	y_to_check;

	x_to_check = 0;
	y_to_check = 0;
	while (probe->next_touch_x >= 0 && probe->next_touch_x <= win->wdth
		&& probe->next_touch_y >= 0 && probe->next_touch_y <= win->hgt)
	{
		x_to_check = probe->next_touch_x;
		y_to_check = probe->next_touch_y;
		if (probe->orientation == NW || probe->orientation == NE)
			y_to_check += -1;
		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			probe->wall_hit_x = probe->next_touch_x;
			probe->wall_hit_y = probe->next_touch_y;
			probe->horizontal_wall_hit = 1;
			probe->vertical_wall_hit = 0;
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
