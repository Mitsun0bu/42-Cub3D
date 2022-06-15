/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/15 18:24:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ray_casting(t_data *data, t_player *player, t_ray *ray)
{
	int	column_i;

	ray->angle = player->rotation_angle - (player->fov / 2);
	column_i = -1;
	while(++column_i < 1)
	{
		ray->line.x_start = player->x;
		ray->line.y_start = player->y;
		ray->line.x_end = player->x + cos(ray->angle) * 30;
		ray->line.y_end = player->y + sin(ray->angle) * 30;
		// ray->line.color = RED;
		// render_line(data, &data->mini_map, ray->line);

		////////////////////////////////////////////////////////////////
		///	START DDA
		////////////////////////////////////////////////////////////////
		dda_algorithm(data, &data->player, &data->ray);
		////////////////////////////////////////////////////////////////
		/// END DDA
		///////////////////////////////////////////////////////////////

		ray->angle += player->fov / data->ray.n_rays;
		ray->angle = normalize_angle(ray->angle);
		// ray->angle = fabs(normalize_angle(ray->angle)); //Should we use abs value ?
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

void	dda_algorithm(t_data *data, t_player *player, t_ray *ray)
{
	int	horizontal_wall_hit;
	int	vertical_wall_hit;

	horizontal_wall_hit = NOT_FOUND;
	vertical_wall_hit = NOT_FOUND;

	// Get ray orientation
	get_ray_orientation(player, ray);

	// Find horizontal wall_hit
	if (find_horizontal_wall_hit(map, player, ray) == SUCCESS)
		horizontal_wall_hit = FOUND;

	// Find horizontal wall_hit
	if (find_vertical_wall_hit(map, player, ray) == SUCCESS)
		horizontal_wall_hit = FOUND;

	////////////////////////////////////////////////////////////////
	/// CALCULATE HORIZONTAL AND VERTICAL DISTANCES
	////////////////////////////////////////////////////////////////
}

void	get_ray_orientation(t_player *player, t_ray *ray)
{
	if (ray->line.x_end > player->x && ray->line.y_end < player->y)
		ray->orientation = NE;
	else if (ray->line.x_end < player->x && ray->line.y_end < player->y)
		ray->orientation = NW;
	else if (ray->line.x_end > player->x && ray->line.y_end > player->y)
		ray->orientation = SE;
	else if (ray->line.x_end < player->x && ray->line.y_end > player->y)
		ray->orientation = SW;
}

int	find_horizontal_wall_hit(t_map *map, t_player *player, t_ray *ray)
{
	// Find y-coordinate of the closest horizontal map grid intersection
	ray->y_intercept = floor(player->y / map->cell_size) * map->cell_size;
	if (ray->orientation == SE || ray->orientation == SW)
		ray->y_intercept += map->cell_size;
	// Find x-coordinate of the closest horizontal map grid intersection
	ray->x_intercept = player->x + (ray->y_intercept - player->y) / tan(ray->angle);

	// Calculate the y_step and x_step increment
	ray->y_step = map->cell_size;
	if (ray->orientation == NE || ray->orientation == NW)
		ray->y_step *= -1;
	ray->x_step = map->cell_size / tan(ray->angle);
	if (ray->x_step > 0 && (ray->orientation == NW || ray->orientation == SW))
		ray->x_step *= -1;
	else if (ray->x_step < 0 && (ray->orientation == NE || ray->orientation == SE))
		ray->x_step *= -1;
	// CHECK IF THIS CAN BE SIMPLIFIED BECAUSE WE HAVE NE, NW, SE or SW orientation

	double	next_horizontal_touch_x;
	double	next_horizontal_touch_y;

	next_horizontal_touch_x = ray->x_intercept;
	next_horizontal_touch_y = ray->y_intercept;
	if (ray->orientation == NE || ray->orientation == NW)
		next_horizontal_touch_y --;
	// Increment x_step and y_step until we find a wall
	while(next_horizontal_touch_x >= 0 && next_horizontal_touch_x <= data->win.wdth && next_horizontal_touch_y >= 0 && next_horizontal_touch_y <= data->win.hgt)
	{
		if (check_collision(data, next_horizontal_touch_x, next_horizontal_touch_y) == SUCCESS)
		{
			ray->horizontal_wall_hit_x = next_horizontal_touch_x;
			ray->horizontal_wall_hit_y = next_horizontal_touch_y;
			ray->line.x_start = player->x;
			ray->line.y_start = player->y;
			ray->line.x_end = ray->horizontal_wall_hit_x;
			ray->line.y_end = ray->horizontal_wall_hit_y;
			ray->line.color = RED;
			render_line(data, &data->mini_map, ray->line);
			return (FOUND);
		}
		else
		{
			next_horizontal_touch_x += ray->x_step;
			next_horizontal_touch_y += ray->y_step;
		}
	}
}

int	find_vertical_wall_hit(t_map *map, t_player *player, t_ray *ray)
{
	// Find x-coordinate of the closest vertical map grid intersection
	ray->x_intercept = floor(player->x / map->cell_size) * map->cell_size;
	if (ray->orientation == NE || ray->orientation == SE)
		ray->x_intercept += map->cell_size;
	// Find y-coordinate of the closest vertical map grid intersection
	ray->y_intercept = player->y + (ray->x_intercept - player->x) * tan(ray->angle);

	// Calculate the y_step and x_step increment
	ray->x_step = map->cell_size;
	if (ray->orientation == NW || ray->orientation == SW)
		ray->x_step *= -1;
	ray->y_step = map->cell_size * tan(ray->angle);
	if (ray->y_step > 0 && (ray->orientation == NE || ray->orientation == NW))
		ray->y_step *= -1;
	else if (ray->y_step < 0 && (ray->orientation == SE || ray->orientation == SW))
		ray->y_step *= -1;
	// CHECK IF THIS CAN BE SIMPLIFIED BECAUSE WE HAVE NE, NW, SE or SW orientation

	double	next_vertical_touch_x;
	double	next_vertical_touch_y;

	next_vertical_touch_x = ray->x_intercept;
	next_vertical_touch_y = ray->y_intercept;
	if (ray->orientation == NW || ray->orientation == SW)
		next_vertical_touch_x --;
	// Increment x_step and y_step until we find a wall
	while(next_vertical_touch_x >= 0 && next_vertical_touch_x <= data->win.wdth && next_vertical_touch_y >= 0 && next_vertical_touch_y <= data->win.hgt)
	{
		if (check_collision(data, next_vertical_touch_x, next_vertical_touch_y) == SUCCESS)
		{
			ray->vertical_wall_hit_x = next_vertical_touch_x;
			ray->vertical_wall_hit_y = next_vertical_touch_y;
			ray->line.x_start = player->x;
			ray->line.y_start = player->y;
			ray->line.x_end = ray->vertical_wall_hit_x;
			ray->line.y_end = ray->vertical_wall_hit_y;
			ray->line.color = RED;
			render_line(data, &data->mini_map, ray->line);
			return (FOUND);
		}
		else
		{
			next_vertical_touch_x += ray->x_step;
			next_vertical_touch_y += ray->y_step;
		}
	}
}