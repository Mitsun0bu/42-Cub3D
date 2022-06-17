/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 17:52:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ray_casting(t_data *data)
{
	int		column_i;
	double	ray_angle;

	ray_angle = data->player.rotation_angle - (data->player.fov / 2);
	column_i = -1;
	while(++column_i < data->n_rays)
	{
		dda_algorithm(data, ray_angle, column_i);
		data->ray_tab[column_i].line.x_start = data->player.x;
		data->ray_tab[column_i].line.y_start = data->player.y;
		data->ray_tab[column_i].line.x_end = data->ray_tab[column_i].wall_hit_x;
		data->ray_tab[column_i].line.y_end = data->ray_tab[column_i].wall_hit_y;
		data->ray_tab[column_i].line.color = RED;
		// render_line(data, &data->mini_map, data->ray_tab[column_i].line);
		ray_angle += data->player.fov / data->n_rays;
	}
}
