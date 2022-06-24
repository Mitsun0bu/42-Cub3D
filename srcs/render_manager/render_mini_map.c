/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/24 16:09:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	set_player_param(t_mini_map *mini_map);
static void	set_tile_and_walls_param(t_mini_map *mini_map);

void	render_mini_map(t_data *data)
{
	set_player_param(&data->mini_map);
	set_tile_and_walls_param(&data->mini_map);
	data->mini_map.y_max = MM_HGT / MM_CELL_SIZE;
	data->mini_map.x_max = MM_WDTH / MM_CELL_SIZE;
	data->mini_map.y = 0;
	while (data->mini_map.y < data->mini_map.y_max)
	{
		data->mini_map.x = 0;
		while (data->mini_map.x < data->mini_map.x_max)
		{
			printf("x = %d, y = %d\n", data->mini_map.x, data->mini_map.y);
			printf("x_max = %d, y_max = %d\n", data->mini_map.x_max, data->mini_map.y_max);
			printf("player_x = %d, player_y = %d\n", data->mini_map.player.x, data->mini_map.player.y);
			data->mini_map.tile.x = data->mini_map.x;
			data->mini_map.tile.y = data->mini_map.y;
			data->mini_map.wall.x = data->mini_map.x;
			data->mini_map.wall.y = data->mini_map.y;
			// NW of the map
			if (data->mini_map.y < (data->mini_map.player.y / MM_CELL_SIZE) &&
				data->mini_map.x < (data->mini_map.player.x / MM_CELL_SIZE))
			{
				int	y_to_check;
				int	x_to_check;

				y_to_check = (data->player.y / CELL_SIZE) - data->mini_map.y;
				x_to_check = (data->player.x / CELL_SIZE) - data->mini_map.x;

				if (y_to_check <= 0)
					y_to_check = 0;
				else if (y_to_check > data->mini_map.y_max)
					y_to_check = data->mini_map.y_max;
				if (x_to_check <= 0)
					x_to_check = 0;
				else if (x_to_check > data->mini_map.x_max)
					x_to_check = data->mini_map.x_max;

				printf("NW :: y_to_check = %d, x_to_check = %d\n", y_to_check, x_to_check);
				if (data->map.tab[y_to_check][x_to_check] != '1')
					render_rect(data, &data->game, data->mini_map.tile);
				else
					render_rect(data, &data->game, data->mini_map.wall);
			}
			// NE of the map
			else if (data->mini_map.y < (data->mini_map.player.y / MM_CELL_SIZE) &&
				data->mini_map.x > (data->mini_map.player.x / MM_CELL_SIZE))
			{
				int	y_to_check;
				int	x_to_check;

				y_to_check = (data->player.y / CELL_SIZE) - data->mini_map.y;
				x_to_check = (data->player.x / CELL_SIZE) + data->mini_map.x;

				if (y_to_check <= 0)
					y_to_check = 0;
				else if (y_to_check > data->mini_map.y_max)
					y_to_check = data->mini_map.y_max;
				if (x_to_check <= 0)
					x_to_check = 0;
				else if (x_to_check > data->mini_map.x_max)
					x_to_check = data->mini_map.x_max;

				printf("NE :: y_to_check = %d, x_to_check = %d\n", y_to_check, x_to_check);
				if (data->map.tab[y_to_check][x_to_check] != '1')
					render_rect(data, &data->game, data->mini_map.tile);
				else
					render_rect(data, &data->game, data->mini_map.wall);
			}
			// SE of the map
			else if (data->mini_map.y > (data->mini_map.player.y / MM_CELL_SIZE) &&
				data->mini_map.x > (data->mini_map.player.x / MM_CELL_SIZE))
			{
				int	y_to_check;
				int	x_to_check;

				y_to_check = (data->player.y / CELL_SIZE) + data->mini_map.y;
				x_to_check = (data->player.x / CELL_SIZE) + data->mini_map.x;

				if (y_to_check <= 0)
					y_to_check = 0;
				else if (y_to_check > data->mini_map.y_max)
					y_to_check = data->mini_map.y_max;
				if (x_to_check <= 0)
					x_to_check = 0;
				else if (x_to_check > data->mini_map.x_max)
					x_to_check = data->mini_map.x_max;

				printf("SE :: y_to_check = %d, x_to_check = %d\n", y_to_check, x_to_check);
				if (data->map.tab[y_to_check][x_to_check] != '1')
					render_rect(data, &data->game, data->mini_map.tile);
				else
					render_rect(data, &data->game, data->mini_map.wall);
			}
			// SW of the map
			else if(data->mini_map.y > (data->mini_map.player.y / MM_CELL_SIZE) &&
				data->mini_map.x < (data->mini_map.player.x / MM_CELL_SIZE))
			{
				int	y_to_check;
				int	x_to_check;

				y_to_check = (data->player.y / CELL_SIZE) + data->mini_map.y;
				x_to_check = (data->player.x / CELL_SIZE) - data->mini_map.x;

				if (y_to_check <= 0)
					y_to_check = 0;
				else if (y_to_check > data->mini_map.y_max)
					y_to_check = data->mini_map.y_max;
				if (x_to_check <= 0)
					x_to_check = 0;
				else if (x_to_check > data->mini_map.x_max)
					x_to_check = data->mini_map.x_max;

				printf("SW :: y_to_check = %d, x_to_check = %d\n", y_to_check, x_to_check);
				if (data->map.tab[y_to_check][x_to_check] != '1')
					render_rect(data, &data->game, data->mini_map.tile);
				else
					render_rect(data, &data->game, data->mini_map.wall);
			}
			data->mini_map.x ++;
		}
		data->mini_map.y ++;
	}
	render_rect(data, &data->game, data->mini_map.player);
}

static void	set_player_param(t_mini_map *mini_map)
{
	mini_map->player.x = MM_WDTH / 2;
	mini_map->player.y = MM_HGT / 2;
	mini_map->player.wdth = MM_CELL_SIZE;
	mini_map->player.hgt = MM_CELL_SIZE;
	mini_map->player.color = RED;
}

static void	set_tile_and_walls_param(t_mini_map *mini_map)
{
	mini_map->tile.wdth = MM_CELL_SIZE;
	mini_map->tile.hgt = MM_CELL_SIZE;
	mini_map->tile.color = WHITE;
	mini_map->wall.wdth = MM_CELL_SIZE;
	mini_map->wall.hgt = MM_CELL_SIZE;
	mini_map->wall.color = BLACK;
}
