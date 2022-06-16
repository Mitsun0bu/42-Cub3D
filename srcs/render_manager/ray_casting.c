/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/16 10:01:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ray_casting(t_data *data)
{
	int	column_i;

	data->ray.angle = data->player.rotation_angle - (data->player.fov / 2);
	column_i = -1;
	while(++column_i < 1)
	{
		data->ray.line.x_start = data->player.x;
		data->ray.line.y_start = data->player.y;
		data->ray.line.x_end = data->player.x + cos(data->ray.angle) * 30;
		data->ray.line.y_end = data->player.y + sin(data->ray.angle) * 30;
		// data->ray.line.color = RED;
		// render_line(data, &data->mini_map, data->ray.line);

		////////////////////////////////////////////////////////////////
		///	START DDA
		////////////////////////////////////////////////////////////////
		dda_algorithm(data);
		////////////////////////////////////////////////////////////////
		/// END DDA
		///////////////////////////////////////////////////////////////

		data->ray.angle += data->player.fov / data->ray.n_rays;
		data->ray.angle = normalize_angle(data->ray.angle);
		// data->ray.angle = fabs(normalize_angle(data->ray.angle)); //Should we use abs value ?
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

void	dda_algorithm(t_data *data)
{
	int	horizontal_wall_hit;
	int	vertical_wall_hit;

	horizontal_wall_hit = NOT_FOUND;
	vertical_wall_hit = NOT_FOUND;

	// Get ray orientation
	get_ray_orientation(&data->player, &data->ray);

	// Find horizontal wall_hit
	if (find_horizontal_wall_hit(data) == SUCCESS)
		horizontal_wall_hit = FOUND;

	// Find horizontal wall_hit
	if (find_vertical_wall_hit(data) == SUCCESS)
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

int	find_horizontal_wall_hit(t_data *data)
{
	get_grid_intercept(&data->map, &data->player, &data->ray, HORIZONTAL);
	get_grid_step(&data->map, &data->ray, HORIZONTAL);
	find_wall_hit(data, HORIZONTAL);
}

int	find_vertical_wall_hit(t_data *data)
{
	get_grid_intercept(&data->map, &data->player, &data->ray, VERTICAL);
	get_grid_step(&data->map, &data->ray, VERTICAL);
	find_wall_hit(data, VERTICAL);
}

void	get_grid_intercept(t_map *map, t_player *player, t_ray *ray, int grid)
{
	if (grid == HORIZONTAL)
	{
		// Find y-coordinate of the closest horizontal map grid intersection
		ray->y_intercept = floor(player->y / map->cell_size) * map->cell_size;
		if (ray->orientation == SE || ray->orientation == SW)
			ray->y_intercept += map->cell_size;
		// Find x-coordinate of the closest horizontal map grid intersection
		ray->x_intercept = player->x + (ray->y_intercept - player->y) / tan(ray->angle);
	}
	else if (grid == VERTICAL)
	{
		// Find x-coordinate of the closest vertical map grid intersection
		ray->x_intercept = floor(player->x / map->cell_size) * map->cell_size;
		if (ray->orientation == NE || ray->orientation == SE)
			ray->x_intercept += map->cell_size;
		// Find y-coordinate of the closest vertical map grid intersection
		ray->y_intercept = player->y + (ray->x_intercept - player->x) * tan(ray->angle);
	}
}

void	get_grid_step(t_map *map, t_ray *ray, int grid)
{
	if (grid == HORIZONTAL)
	{
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
	}
	else if (grid == VERTICAL)
	{
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
	}
}

void	find_wall_hit(t_data *data, int grid)
{
	double	horizontal_wall_x;
	double	horizontal_wall_y;
	double	vertical_wall_x;
	double	vertical_wall_y;

	get_next_grid_touch(&data->ray, grid);

	if (grid == HORIZONTAL)
		wall_hit_loop(data, limit);
	else if (grid == VERTICAL)
		wall_hit_loop(data, grid);

	// Increment x_step and y_step until we find a wall
	while(data->ray.next_horizontal_touch_x >= 0 && data->ray.next_horizontal_touch_x <= data->win.wdth
		&& data->ray.next_horizontal_touch_y >= 0 && data->ray.next_horizontal_touch_y <= data->win.hgt)
	{
		if (check_collision(data, data->ray.next_horizontal_touch_x, data->ray.next_horizontal_touch_y) == SUCCESS)
		{
			data->ray.horizontal_wall_hit_x = data->ray.next_horizontal_touch_x;
			data->ray.horizontal_wall_hit_y = data->ray.next_horizontal_touch_y;
			data->ray.line.x_start = data->player.x;
			data->ray.line.y_start = data->player.y;
			data->ray.line.x_end = data->ray.horizontal_wall_hit_x;
			data->ray.line.y_end = data->ray.horizontal_wall_hit_y;
			data->ray.line.color = RED;
			render_line(data, &data->mini_map, data->ray.line);
			return (FOUND);
		}
		else
		{
			data->ray.next_horizontal_touch_x += data->ray.x_step;
			data->ray.next_horizontal_touch_y += data->ray.y_step;
		}
	}

	// Increment x_step and y_step until we find a wall
	while(data->ray.next_vertical_touch_x >= 0 && data->ray.next_vertical_touch_x <= data->win.wdth
		&& data->ray.next_vertical_touch_y >= 0 && data->ray.next_vertical_touch_y <= data->win.hgt)
	{
		if (check_collision(data, data->ray.next_vertical_touch_x, data->ray.next_vertical_touch_y) == SUCCESS)
		{
			data->ray.vertical_wall_hit_x = data->ray.next_vertical_touch_x;
			data->ray.vertical_wall_hit_y = data->ray.next_vertical_touch_y;
			data->ray.line.x_start = data->player.x;
			data->ray.line.y_start = data->player.y;
			data->ray.line.x_end = data->ray.vertical_wall_hit_x;
			data->ray.line.y_end = data->ray.vertical_wall_hit_y;
			data->ray.line.color = RED;
			render_line(data, &data->mini_map, data->ray.line);
			return (FOUND);
		}
		else
		{
			data->ray.next_vertical_touch_x += data->ray.x_step;
			data->ray.next_vertical_touch_y += data->ray.y_step;
		}
	}
}

void	get_next_grid_touch(t_ray *ray, int grid)
{
	if (grid == HORIZONTAL)
	{
		ray->next_horizontal_touch_x = ray->x_intercept;
		ray->next_horizontal_touch_y = ray->y_intercept;
		if (ray->orientation == NE || ray->orientation == NW)
			ray->next_horizontal_touch_y --;
	}
	else if (grid == VERTICAL)
	{
		ray->next_vertical_touch_x = ray->x_intercept;
		ray->next_vertical_touch_y = ray->y_intercept;
		if (ray->orientation == NW || ray->orientation == SW)
			ray->next_vertical_touch_x --;
	}
}

void	wall_hit_loop()
{

}