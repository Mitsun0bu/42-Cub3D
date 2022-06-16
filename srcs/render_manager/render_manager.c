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

void	render_manager(t_data *data)
{
	render_mini_map(data);
	ray_casting(data);
	mlx_put_image_to_window(data->win.mlx, data->win.edge, data->mini_map.ptr, 0, 0);
}

void	render_mini_map(t_data *data)
{
	int				x;
	int				y;

	y = -1;
	while (++y < data->map.hgt)
	{
		x = -1;
		while (++x < data->map.wdth)
			render_walls_and_tiles(data, x, y);
	}
	render_player(data);
}

void	render_walls_and_tiles(t_data *data, int x, int y)
{
	t_rect	cell;

	cell.x = x * data->map.cell_size;
	cell.y = y * data->map.cell_size;
	cell.wdth = data->map.cell_size;
	cell.hgt = data->map.cell_size;

	if (data->map.tab[y][x] == '1')
	{
		cell.color = PINK;
		render_rect(data, &data->mini_map, cell);
	}
	else
	{
		cell.color = WHITE;
		render_rect(data, &data->mini_map, cell);
	}
}

void	render_player(t_data *data)
{
	// Draw player
	t_rect	player;

	player.wdth = 10;
	player.hgt = 10;
	player.x = data->player.x - (player.wdth / 2);
	player.y = data->player.y - (player.hgt / 2);
	player.color = YELLOW;
	render_rect(data, &data->mini_map, player);

	//Draw player direction vector
	// t_line	line;

	// line.x_start = data->player.x;
	// line.y_start = data->player.y;
	// line.x_end = data->player.x + cos(data->player.rotation_angle) * 20;
	// line.y_end = data->player.y + sin(data->player.rotation_angle) * 20;
	// line.color = BLACK;
	// render_line(data, &data->mini_map, line);
}