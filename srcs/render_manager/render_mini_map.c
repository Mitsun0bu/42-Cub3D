/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/27 11:59:02 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void render_mini_map_nw(t_data *data);

void	render_mini_map(t_data *data)
{
	data->mini_map.square.wdth = MM_CELL_SIZE;
	data->mini_map.square.hgt = MM_CELL_SIZE;
	render_mini_map_nw(data);
}

static void render_mini_map_nw(t_data *data)
{
	int	x;
	int	y;
	int	limit_x;
	int	limit_y;

	limit_x = 20;
	limit_y = 10;
	data->mini_map.square.y = 10;
	y = (data->player.y / CELL_SIZE) - limit_y;
	if (y < 0)
		y = 0;
	while (y < (data->player.y / CELL_SIZE) + limit_y && y < data->map.hgt)
	{
		data->mini_map.square.x = 10;
		x = (data->player.x / CELL_SIZE) - limit_x;
		if (x < 0)
			x = 0;
		while (x < (data->player.x / CELL_SIZE) + limit_x && x < (int)ft_strlen(data->map.tab[y]))
		{
			if (data->map.tab[y][x] != '1')
			{
				data->mini_map.square.color = WHITE;
				render_rect(data, &data->game, data->mini_map.square);
			}
			else
			{
				data->mini_map.square.color = BLACK;
				render_rect(data, &data->game, data->mini_map.square);
			}
			if (y == (int)floor(data->player.y / CELL_SIZE) && x == (int)floor(data->player.x / CELL_SIZE))
			{
				data->mini_map.square.color = RED;
				render_rect(data, &data->game, data->mini_map.square);
			}
			x ++;
			data->mini_map.square.x += MM_CELL_SIZE;
		}
		y ++;
		data->mini_map.square.y += MM_CELL_SIZE;
	}
}