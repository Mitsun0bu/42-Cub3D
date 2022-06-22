/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:22:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 11:59:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	render_ceiling(t_data *data, int i, double wall_base);
static void	render_floor(t_data *data, int i, double wall_base);
static void	render_wall(t_data *data, double wall_base, double wall_hgt, int i);

void	render_game(t_data *data, t_player *player, t_ray *ray)
{
	double	proj_plane_dist;
	double	wall_hgt;
	double	wall_base;
	int		i;

	i = -1;
	while (++i < data->n_rays)
	{
		ray[i].dist = ray[i].dist * cos(ray[i].angle - player->rot_angle);
		proj_plane_dist = (WIN_WDTH / 2) / (tan(player->fov / 2));
		wall_hgt = (CELL_SIZE / ray[i].dist) * proj_plane_dist;
		wall_base = WIN_HGT / 2 + wall_hgt / 2;
		render_ceiling(data, i, wall_base);
		render_floor(data, i, wall_base);
		render_wall(data, wall_base, wall_hgt, i);
	}
}

static void	render_ceiling(t_data *data, int i, double wall_base)
{
	t_rect	ceiling;

	ceiling.x = i;
	ceiling.y = 0;
	ceiling.wdth = 1;
	ceiling.hgt = wall_base;
	ceiling.color = data->config.ceiling_hex_code;
	if (ceiling.hgt >= 0 && ceiling.hgt <= WIN_HGT)
		render_rect(data, &data->walls, ceiling);
}

static void	render_floor(t_data *data, int i, double wall_base)
{
	t_rect	floor;

	floor.x = i;
	floor.y = wall_base + 1;
	floor.wdth = 1;
	floor.hgt = WIN_HGT - wall_base;
	floor.color = data->config.floor_hex_code;
	if (floor.hgt >= 0 && floor.hgt <= WIN_HGT)
		render_rect(data, &data->walls, floor);
}

static void	render_wall(t_data *data, double wall_base, double wall_hgt, int i)
{
	t_texture	texture;
	t_coord		texture_coord;
	int			color;
	int			i_pixel;
	double		texture_step;

	texture_coord.x = (((int)data->ray_tab[i].wall_hit_x
				+ (int)data->ray_tab[i].wall_hit_y) % CELL_SIZE);
	texture_coord.y = CELL_SIZE;
	texture_step = CELL_SIZE / wall_hgt;
	texture = get_texture(data, i);
	i_pixel = 0;
	while (i_pixel++ < wall_hgt)
	{
		texture_coord.y -= texture_step;
		if (texture_coord.y < 0)
			texture_coord.y = 0;
		color = get_pixel_color_from_texture(&texture, &texture_coord);
		if (wall_base - i_pixel >= 0 && wall_base - i_pixel < WIN_HGT)
			pixel_put(&data->walls, i, wall_base - i_pixel, color);
	}
}
