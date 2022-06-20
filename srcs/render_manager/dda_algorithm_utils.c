/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:44:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 18:51:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_ray_orientation(t_player *player, double ray_angle)
{
	double	x_start;
	double	y_start;
	double	x_end;
	double	y_end;
	int		ray_orientation;

	x_start = player->x;
	y_start = player->y;
	x_end = player->x + cos(ray_angle) * 30;
	y_end = player->y + sin(ray_angle) * 30;
	ray_orientation = 0;
	if (x_end > x_start && y_end < y_start)
		ray_orientation = NE;
	else if (x_end < x_start && y_end < y_start)
		ray_orientation = NW;
	else if (x_end > x_start && y_end > y_start)
		ray_orientation = SE;
	else if (x_end < x_start && y_end > y_start)
		ray_orientation = SW;
	return (ray_orientation);
}

void	get_probes_len(t_player *player, t_probe *h_probe, t_probe *v_probe)
{
	if (h_probe->horizontal_wall_hit)
		h_probe->len = calculate_distance(player->x, player->y,
				h_probe->wall_hit_x, h_probe->wall_hit_y);
	else
		h_probe->len = FLT_MAX;
	if (v_probe->vertical_wall_hit)
		v_probe->len = calculate_distance(player->x, player->y,
				v_probe->wall_hit_x, v_probe->wall_hit_y);
	else
		v_probe->len = FLT_MAX;
}

void	update_ray(t_ray *ray, double angle, t_probe *h_probe, t_probe *v_probe)
{
	if (v_probe->len < h_probe->len)
	{
		ray->dist = v_probe->len;
		ray->orientation = v_probe->orientation;
		ray->wall_hit_x = v_probe->wall_hit_x;
		ray->wall_hit_y = v_probe->wall_hit_y;
		ray->grid_hit = VERTICAL;
	}
	else
	{
		ray->dist = h_probe->len;
		ray->orientation = h_probe->orientation;
		ray->wall_hit_x = h_probe->wall_hit_x;
		ray->wall_hit_y = h_probe->wall_hit_y;
		ray->grid_hit = HORIZONTAL;
	}
	ray->angle = angle;
}
