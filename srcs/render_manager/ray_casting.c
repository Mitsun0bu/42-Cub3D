/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/16 19:25:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	ray_casting(t_data *data)
// {
// 	int	column_i;
// 	data->ray.angle = data->player.rotation_angle - (data->player.fov / 2);
// 	normalize_angle(data->ray.angle);
// 	column_i = -1;
// 	// while(++column_i < 1)
// 	while(++column_i < data->ray.n_rays)
// 	{
// 		// data->ray_tab[i].angle = data->player.rotation_angle - (data->player.fov / 2);
// 		// normalize_angle(data->ray_tab[i].angle);
// 		data->ray.dir_x_start = data->player.x;
// 		data->ray.dir_y_start = data->player.y;
// 		data->ray.dir_x_end = data->player.x + cos(data->ray.angle) * 50;
// 		data->ray.dir_y_end = data->player.y + sin(data->ray.angle) * 50;
// 		// data->ray.line.color = RED;
// 		// render_line(data, &data->mini_map, data->ray.line);
// 		////////////////////////////////////////////////////////////////
// 		///	START DDA
// 		////////////////////////////////////////////////////////////////
// 		dda_algorithm(data);
// 		////////////////////////////////////////////////////////////////
// 		/// END DDA
// 		///////////////////////////////////////////////////////////////
// 		data->ray.line.x_start = data->player.x;
// 		data->ray.line.y_start = data->player.y;
// 		data->ray.line.x_end = data->ray.wall_hit_x;
// 		data->ray.line.y_end = data->ray.wall_hit_y;
// 		data->ray.line.color = RED;
// 		render_line(data, &data->mini_map, data->ray.line);
// 		data->ray.angle += data->player.fov / data->ray.n_rays;
// 		data->ray.angle = normalize_angle(data->ray.angle);
// 		// data->ray.angle = fabs(normalize_angle(data->ray.angle)); //Should we use abs value ?
// 	}
// }

void	ray_casting(t_data *data)
{
	int		column_i;
	double	ray_angle;

	ray_angle = data->player.rotation_angle - (data->player.fov / 2);
	column_i = -1;
	while(++column_i < data->n_rays)
	{
		cast_single_ray(data, ray_angle, column_i);
		ray_angle += data->player.fov / data->n_rays;
	}
}

void	cast_single_ray(t_data *data, double ray_angle, int column_i)
{
	ray_angle = normalize_angle(ray_angle);

	int	is_facing_down = NO;
	int	is_facing_up = NO;
	int	is_facing_left = NO;
	int	is_facing_right = NO;

	if (ray_angle > 0 && ray_angle < M_PI)
		is_facing_down = YES;
	else
		is_facing_up = YES;
	if (ray_angle < M_PI / 2 || ray_angle > 3 * M_PI / 2)
		is_facing_right = YES;
	else
		is_facing_left = YES;

	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;

	///////////////////////////////////////////
	// HORIZONTAL RAY-GRID INTERSECTION CODE
	///////////////////////////////////////////
	int		horizontal_wall_hit = NOT_FOUND;
	double	horizontal_wall_hit_x;
	double	horizontal_wall_hit_y;
	int		grid_hit;

	// Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
    yintercept += isRayFacingDown ? TILE_SIZE : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = player.x + (yintercept - player.y) / tan(rayAngle);

    // Calculate the increment xstep and ystep
    ystep = TILE_SIZE;
    ystep *= isRayFacingUp ? -1 : 1;

    xstep = TILE_SIZE / tan(rayAngle);
    xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
    xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT) {
        float xToCheck = nextHorzTouchX;
        float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);

        if (mapHasWallAt(xToCheck, yToCheck)) {
            // found a wall hit
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            horzWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundHorzWallHit = TRUE;
            break;
        } else {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }
}

double	normalize_angle(double angle)
{
	double	normalized_angle;

	normalized_angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		normalized_angle = (2 * M_PI) + angle;
	return (normalized_angle);
}

void	dda_algorithm(t_data *data)
{
	get_ray_orientation(&data->player, &data->ray);
	find_horizontal_wall_hit(data);
	find_vertical_wall_hit(data);

	////////////////////////////////////////////////////////////////
	///			CALCULATE HORIZONTAL AND VERTICAL DISTANCES		 ///
	////////////////////////////////////////////////////////////////
	data->ray.horizontal_hit_distance = sqrt(pow((data->ray.horizontal_wall_hit_x) - (data->player.x), 2) + pow((data->ray.horizontal_wall_hit_y) - (data->player.y), 2));
	data->ray.vertical_hit_distance = sqrt(pow((data->ray.vertical_wall_hit_x) - (data->player.x), 2) + pow((data->ray.vertical_wall_hit_y) - (data->player.y), 2));
	if (data->ray.horizontal_hit_distance < data->ray.vertical_hit_distance)
	{
		data->ray.wall_hit_x = data->ray.horizontal_wall_hit_x;
		data->ray.wall_hit_y = data->ray.horizontal_wall_hit_y;
		data->ray.len = data->ray.horizontal_hit_distance;
		data->ray.grid_hit = HORIZONTAL;
	}
	else
	{
		data->ray.wall_hit_x = data->ray.vertical_wall_hit_x;
		data->ray.wall_hit_y = data->ray.vertical_wall_hit_y;
		data->ray.len = data->ray.vertical_hit_distance;
		data->ray.grid_hit = VERTICAL;
	}
}

// void	get_ray_orientation(t_player *player, t_ray *ray)
// {
// 	if (ray->dir_x_end > player->x && ray->dir_y_end < player->y)
// 		ray->orientation = NE;
// 	else if (ray->dir_x_end < player->x && ray->dir_y_end < player->y)
// 		ray->orientation = NW;
// 	else if (ray->dir_x_end > player->x && ray->dir_y_end > player->y)
// 		ray->orientation = SE;
// 	else if (ray->dir_x_end < player->x && ray->dir_y_end > player->y)
// 		ray->orientation = SW;
// }

void	find_horizontal_wall_hit(t_data *data)
{
	get_grid_intercept(&data->map, &data->player, &data->ray, HORIZONTAL);
	get_grid_step(&data->map, &data->ray, HORIZONTAL);
	find_wall_hit(data, HORIZONTAL);
}

void	find_vertical_wall_hit(t_data *data)
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
		// if (ray->orientation == SE || ray->orientation == SW)
		if (ray->is_facing_down)
			ray->y_intercept += map->cell_size;
		// Find x-coordinate of the closest horizontal map grid intersection
		ray->x_intercept = player->x + (ray->y_intercept - player->y) / tan(ray->angle);
	}
	else if (grid == VERTICAL)
	{
		// Find x-coordinate of the closest vertical map grid intersection
		ray->x_intercept = floor(player->x / map->cell_size) * map->cell_size;
		// if (ray->orientation == NE || ray->orientation == SE)
		if (ray->is_facing_right)
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
		// if (ray->orientation == NE || ray->orientation == NW)
		if (ray->is_facing_up)
			ray->y_step *= -1;
		ray->x_step = map->cell_size / tan(ray->angle);
		// if ((ray->orientation == NW || ray->orientation == SW) && ray->x_step > 0)
		if (ray->is_facing_left && ray->x_step > 0)
			ray->x_step *= -1;
		// else if ((ray->orientation == NE || ray->orientation == SE) && ray->x_step < 0)
		else if (ray->is_facing_right && ray->x_step < 0)
			ray->x_step *= -1;
	}
	else if (grid == VERTICAL)
	{
		// Calculate the y_step and x_step increment
		ray->x_step = map->cell_size;
		// if (ray->orientation == NW || ray->orientation == SW) // TO CHANGE ??? NW / NE
		if (ray->is_facing_left)
			ray->x_step *= -1;
		ray->y_step = map->cell_size * tan(ray->angle);
		// if ((ray->orientation == NE || ray->orientation == NW) && ray->y_step > 0)
		if (ray->is_facing_up && ray->y_step > 0)
			ray->y_step *= -1;
		else if ((ray->orientation == SE || ray->orientation == SW) && ray->y_step < 0 )
			ray->y_step *= -1;
	}
}

void	find_wall_hit(t_data *data, int grid)
{
	get_next_grid_touch(&data->ray, grid);
	if (grid == HORIZONTAL)
		horizontal_wall_hit_loop(data, &data->win, &data->player, &data->ray);
	else if (grid == VERTICAL)
		vertical_wall_hit_loop(data, &data->win, &data->player, &data->ray);
}

void	get_next_grid_touch(t_ray *ray, int grid)
{
	if (grid == HORIZONTAL)
	{
		ray->next_horizontal_touch_x = ray->x_intercept;
		ray->next_horizontal_touch_y = ray->y_intercept;
		// if (ray->orientation == NE || ray->orientation == NW)
		// 	ray->next_horizontal_touch_y --;
	}
	else if (grid == VERTICAL)
	{
		ray->next_vertical_touch_x = ray->x_intercept;
		ray->next_vertical_touch_y = ray->y_intercept;
		// if (ray->orientation == NW || ray->orientation == SW)
		// 	ray->next_vertical_touch_x --;
	}
}

void	horizontal_wall_hit_loop(t_data *data, t_win *win, t_player *player, t_ray *ray)
{
	(void)player;

	// Increment x_step and y_step until we find a wall
	while(ray->next_horizontal_touch_x >= 0 && ray->next_horizontal_touch_x <= win->wdth
		&& ray->next_horizontal_touch_y >= 0 && ray->next_horizontal_touch_y <= win->hgt)
	{
		double	x_to_check;
		double	y_to_check;
		x_to_check = ray->next_horizontal_touch_x;
		y_to_check = ray->next_horizontal_touch_y;
		// if (ray->orientation == NE || ray->orientation == NW)
		if (ray->is_facing_up)
			y_to_check = ray->next_horizontal_touch_y - 1;
		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			ray->horizontal_wall_hit_x = ray->next_horizontal_touch_x;
			ray->horizontal_wall_hit_y = ray->next_horizontal_touch_y;
			break;
		}
		else
		{
			ray->next_horizontal_touch_x += ray->x_step;
			ray->next_horizontal_touch_y += ray->y_step;
		}
	}
}

void	vertical_wall_hit_loop(t_data *data, t_win *win, t_player *player, t_ray *ray)
{
	(void)player;
	double	x_to_check;
	double	y_to_check;

	// Increment x_step and y_step until we find a wall
	while(ray->next_vertical_touch_x >= 0 && ray->next_vertical_touch_x <= win->wdth
		&& ray->next_vertical_touch_y >= 0 && ray->next_vertical_touch_y <= win->hgt)
	{
		x_to_check = ray->next_vertical_touch_x;
		// if (ray->orientation == NW || ray->orientation == SW)
		if (ray->is_facing_left)
			x_to_check --;
		y_to_check = ray->next_vertical_touch_y;
		if (check_collision(data, x_to_check, y_to_check) == SUCCESS)
		{
			ray->vertical_wall_hit_x = ray->next_vertical_touch_x;
			ray->vertical_wall_hit_y = ray->next_vertical_touch_y;
			break;
		}
		else
		{
			ray->next_vertical_touch_x += ray->x_step;
			ray->next_vertical_touch_y += ray->y_step;
		}
	}
}