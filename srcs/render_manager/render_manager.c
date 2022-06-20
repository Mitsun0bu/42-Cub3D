/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:36:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/07 09:48:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The render_manager.c file is where we :
	- initialize the mini_map image.
	- add pixels to the image that correspond to:
		- the map
		- the player position
		- the rays
	- put the mini_map imge to the window
*/

#include "main.h"

static void	render_game(t_data *data);
static void	display_wall(t_data *data, double column_hgt, int i);
static t_texture	get_texture(t_data *data, int i);
static int	get_tex_color(t_texture *texture, t_coord *coord);

void	render_manager(t_data *data)
{
	// render_mini_map(data);
	ray_casting(data);
	render_game(data);
	mlx_put_image_to_window(data->win.mlx, data->win.edge, data->walls.ptr, 0, 0);
	// mlx_put_image_to_window(data->win.mlx, data->win.edge, data->mini_map.ptr, 0, 0);
}

static void	render_game(t_data *data)
{
	double	distance_proj_plane;
	double	column_hgt;
	int		i;

	i = -1;
	while (++i < data->n_rays)
	{
		data->ray_tab[i].distance = data->ray_tab[i].distance * cos(data->ray_tab[i].angle - data->player.rotation_angle);
		distance_proj_plane = (data->win.wdth / 2) / (tan(data->player.fov / 2));
		column_hgt = (data->map.cell_size / data->ray_tab[i].distance) * distance_proj_plane;

		if (data->win.hgt/2+column_hgt/2 >= 0 && data->win.hgt/2+column_hgt/2 <= data->win.hgt)
			render_rect(data, &data->walls, (t_rect){i, 0, 1, data->win.hgt/2+column_hgt/2, data->config.ceiling_hex_code});

		if ( data->win.hgt - (data->win.hgt/2+column_hgt/2) >= 0 &&  data->win.hgt - (data->win.hgt/2+column_hgt/2) <= data->win.hgt)
			render_rect(data, &data->walls, (t_rect){i, data->win.hgt/2+column_hgt/2 + 1, 1, data->win.hgt - (data->win.hgt/2+column_hgt/2), data->config.floor_hex_code});
		display_wall(data, column_hgt, i);
	}
}

static void	display_wall(t_data *data, double column_hgt, int i)
{
	t_texture	texture;
	int			color;
	int			j;

	double hit_x = (((int)data->ray_tab[i].wall_hit_x + (int)data->ray_tab[i].wall_hit_y) % data->map.cell_size);
	double	hit_y = data->map.cell_size;
	double	texture_step = data->map.cell_size / column_hgt;

	texture = get_texture(data, i);
	j = 0;
	while (j++ < column_hgt)
	{
		hit_y -= texture_step;
		if (hit_y < 0)
			hit_y = 0;
		color = get_tex_color(&texture, &(t_coord){hit_x, hit_y});
		if (data->win.hgt/2+column_hgt/2 - j >= 0 && data->win.hgt/2+column_hgt/2 - j <= data->win.hgt)
			pixel_put(&data->walls, i, data->win.hgt/2+column_hgt/2 - j, color);
	}
}

static t_texture	get_texture(t_data *data, int i)
{
	if (data->player.orientation == 'N')
	{
		if (data->ray_tab[i].grid_hit == HORIZONTAL)
		{
			return (data->south_texture);
		}
		else
		{
			if (data->player.x > data->ray_tab[i].wall_hit_x)
				return (data->east_texture);
			else
				return (data->west_texture);
		}
	}
	else if (data->player.orientation == 'S')
	{
		if (data->ray_tab[i].grid_hit == HORIZONTAL)
			return (data->north_texture);
		else
		{
			if (data->player.x < data->ray_tab[i].wall_hit_x)
				return (data->west_texture);
			else
				return (data->east_texture);
		}
	}
	else if (data->player.orientation == 'E')
	{
		if (data->ray_tab[i].grid_hit == VERTICAL)
		{
			return (data->west_texture);
		}
		else
		{
			if (data->player.y > data->ray_tab[i].wall_hit_y)
				return (data->south_texture);
			else
				return (data->north_texture);
		}
	}
	else if (data->player.orientation == 'W')
	{
		if (data->ray_tab[i].grid_hit == VERTICAL)
		{
			return (data->east_texture);
		}
		else
		{
			if (data->player.y < data->ray_tab[i].wall_hit_y)
				return (data->north_texture);
			else
				return (data->south_texture);
		}
	}
	return (data->south_texture);
}

static int	get_tex_color(t_texture *texture, t_coord *coord)
{
	if (coord->x >= 0 && coord->x < texture->wdth && coord->y >= 0 && coord->y < texture->hgt)
	{
		return (*(int*)(texture->ptr + (4 * texture->wdth * (int)coord->y) + (4 * (int)coord->x)));
	}
	return (FAILED);
}
