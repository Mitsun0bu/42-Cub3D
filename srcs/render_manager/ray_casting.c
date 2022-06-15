/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/15 12:01:18 by llethuil         ###   ########lyon.fr   */
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
		ray->angle += player->fov / data->ray.n_rays;
	}
}