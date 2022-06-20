/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map_old.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 18:50:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_mini_map(t_data *data)
{
	int				x;
	int				y;

	render_background(data);
	y = -1;
	while (++y < data->map.hgt)
	{
		x = -1;
		while (++x < (int)ft_strlen(data->map.tab[y]))
			render_walls_and_tiles(data, x, y);
	}
	render_player(data);
}

void	render_background(t_data *data)
{
	t_rect	background;

	background.x = 0;
	background.y = 0;
	background.wdth = data->win.wdth - 1;
	background.hgt = data->win.hgt - 1;
	background.color = BLACK;
	render_rect(data, &data->mini_map, background);
}

void	render_walls_and_tiles(t_data *data, int x, int y)
{
	t_rect	cell;

	cell.x = x * data->map.cell_size;
	cell.y = y * data->map.cell_size;
	cell.wdth = data->map.cell_size - 1;
	cell.hgt = data->map.cell_size - 1;

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
	// line.x_end = data->player.x + cos(data->player.rot_angle) * 20;
	// line.y_end = data->player.y + sin(data->player.rot_angle) * 20;
	// line.color = BLACK;
	// render_line(data, &data->mini_map, line);
}