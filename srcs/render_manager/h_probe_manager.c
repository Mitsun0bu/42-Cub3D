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

void	init_h_probe(t_player *player, double angle, t_probe *probe)
{
	int	we_oriented;
	int	ea_oriented;

	probe->orientation = get_ray_orientation(player, angle);
	probe->wall_hit_x = 0;
	probe->wall_hit_y = 0;
	we_oriented = (probe->orientation == NW || probe->orientation == SW);
	ea_oriented = (probe->orientation == NE || probe->orientation == SE);
	probe->y_intcp = floor(player->y / CELL_SIZE) * CELL_SIZE;
	if (probe->orientation == SW || probe->orientation == SE)
		probe->y_intcp += CELL_SIZE;
	probe->x_intcp = player->x + (probe->y_intcp - player->y) / tan(angle);
	probe->y_step = CELL_SIZE;
	if (probe->orientation == NW || probe->orientation == NE)
		probe->y_step *= -1;
	probe->x_step = CELL_SIZE / tan(angle);
	if (we_oriented && probe->x_step > 0)
		probe->x_step *= -1;
	if (ea_oriented && probe->x_step < 0)
		probe->x_step *= -1;
	probe->next_hit_x = probe->x_intcp;
	probe->next_hit_y = probe->y_intcp;
	probe->horizontal_wall_hit = 0;
	probe->vertical_wall_hit = 0;
}

void	find_h_probe_wall_hit(t_data *data, t_map *map, t_probe *probe)
{
	float	x_to_check;
	float	y_to_check;

	while (probe->next_hit_x >= 0 && probe->next_hit_x <= map->wdth * CELL_SIZE
		&& probe->next_hit_y >= 0 && probe->next_hit_y <= map->hgt * CELL_SIZE)
	{
		x_to_check = probe->next_hit_x;
		y_to_check = probe->next_hit_y;
		if (probe->orientation == NW || probe->orientation == NE)
			y_to_check += -1;
		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			probe->wall_hit_x = probe->next_hit_x;
			probe->wall_hit_y = probe->next_hit_y;
			probe->horizontal_wall_hit = 1;
			probe->vertical_wall_hit = 0;
			probe->grid_hit = HORIZONTAL;
			break ;
		}
		else
		{
			probe->next_hit_x += probe->x_step;
			probe->next_hit_y += probe->y_step;
		}
	}
}
