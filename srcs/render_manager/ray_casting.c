/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/15 15:18:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ray_casting(t_data *data, t_player *player, t_ray *ray)
{
	int	column_i;

	ray->angle = player->rotation_angle - (player->fov / 2);
	column_i = -1;
	while(++column_i < ray->n_rays)
	{
		ray->line.x_start = player->x;
		ray->line.y_start = player->y;
		ray->line.x_end = player->x + cos(ray->angle) * 30;
		ray->line.y_end = player->y + sin(ray->angle) * 30;
		ray->line.color = RED;
		render_line(data, &data->mini_map, ray->line);

		// START DDA ALGORITHM

		// Get ray orientation
		if (ray->line.x_end > player->x && ray->line.y_end < player->y)
			ray->orientation = NE;
		else if (ray->line.x_end < player->x && ray->line.y_end < player->y)
			ray->orientation = NW;
		else if (ray->line.x_end > player->x && ray->line.y_end > player->y)
			ray->orientation = SE;
		else if (ray->line.x_end < player->x && ray->line.y_end > player->y)
			ray->orientation = SW;

		// Horizontal ray intersection with map grid
		// Find y-coordinate of the closest horizontal map grid intersection
		ray->y_intercept = floor(player->y / data->map.cell_size) * data->map.cell_size;
		if (ray->orientation == SE || ray->orientation == SW)
			ray->y_intercept += data->map.cell_size;
		// Find x-coordinate of the closest horizontal map grid intersection
		ray->x_intercept = player->x + (ray->y_intercept - player->y) / tan(ray->angle);

		ray->x_step = data->map.cell_size / tan(ray->angle);
		ray->y_step = data->map.cell_size;

		// Vertical ray intersection with map grid
		ray->x_step = data->map.cell_size;
		ray->y_step = data->map.cell_size * tan(ray->angle);


		// END DDA ALGORITHM

		ray->angle += player->fov / data->ray.n_rays;
		normalize_angle(ray->angle);
	}
}

double	normalize_angle(double angle)
{
	double	normalized_angle;

	normalized_angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (normalized_angle);
}