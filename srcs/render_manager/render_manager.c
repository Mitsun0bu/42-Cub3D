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

static void	print_mini_map(t_data *data);

void	render_manager(t_data *data)
{
	print_mini_map(data);
	// ray_casting(data);
	mlx_put_image_to_window(data->win.mlx, data->win.edge, data->mini_map.ptr, 0, 0);
	// render_mini_map(data, config);
	// mlx_put_image_to_window(data->win.mlx, data->win.edge, data->walls.ptr, 0, 0);
	// mlx_put_image_to_window(win->mlx, win->edge, data->mini_map.ptr, 0, 0);
}

static void	print_mini_map(t_data *data)
{
	int				x;
	int				y;

	y = -1;
	while (++y < data->map.hgt)
	{
		x = -1;
		while (++x < data->map.wdth)
		{
			t_rect	tile;
			
			tile.x = x * data->map.tile_size;
			tile.y = y * data->map.tile_size;
			tile.wdth = data->map.tile_size;
			tile.hgt = data->map.tile_size;
			
			// Drawing walls and player
			if (data->map.tab[y][x] == '1')
			{
				tile.color = PINK;
				render_rect(data, &data->mini_map, tile);
			}	
			else
			{
				tile.color = WHITE;
				render_rect(data, &data->mini_map, tile);
			}
		}	
	}
	t_rect	player;
	
	player.wdth = 10;
	player.hgt = 10;
	player.x = data->player.x - (player.wdth / 2);
	player.y = data->player.y - (player.hgt / 2);
	player.color = YELLOW;
	render_rect(data, &data->mini_map, player);

	t_line	line;

	line.start_x = data->player.x;
	line.start_y = data->player.y;
	line.end_x = data->player.x + cos(data->player.rotation_angle) * 20;
	line.end_y = data->player.y + sin(data->player.rotation_angle) * 20;
	line.color = BLACK;
	render_line(data, &data->mini_map, line);
}
