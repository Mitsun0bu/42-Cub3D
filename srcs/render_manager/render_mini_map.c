/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/24 11:59:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	get_player_config(t_player *player, t_mini_map *mini_map);
static void	set_tile_and_walls_specs(t_mini_map *mini_map);
static void	render_wall(t_data *data, t_map *map, int x, int y);
static void	cam_init(t_map *map, t_player *player, t_mini_map *mini_map);

// void	render_mini_map(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	t_rect	tile;

// 	tile.wdth = 4;
// 	tile.hgt = 4;
// 	tile.color = WHITE;
// 	y = -1;
// 	while (++y < data->map.hgt)
// 	{
// 		x = -1;
// 		while (++x < (int)ft_strlen(data->map.tab[y]))
// 		{
// 			tile.x = (x * 7) + 10;
// 			tile.y = (y * 7) + 10;
// 			if (data->map.tab[y][x] != '1')
// 				render_rect(data, &data->game, tile);
// 			else
// 				render_wall(data, &data->map, x, y);
// 		}
// 	}
// 	render_player(data);
// }

// static void	render_wall(t_data *data, t_map *map, int x, int y)
// {
// 	t_rect	wall;

// 	wall.x = (x * 7) + 10;
// 	wall.y = (y * 7) + 10;
// 	wall.wdth = 4;
// 	wall.hgt = 4;
// 	wall.color = BLACK;
// 	if (x > 0 && map->tab[y][x - 1] != '1')
// 		render_rect(data, &data->game, wall);
// 	if (x < (int)ft_strlen(map->tab[y]) && map->tab[y][x + 1] != '1')
// 		if (map->tab[y][x + 1] != '1' && map->tab[y][x + 1] != 0)
// 			render_rect(data, &data->game, wall);
// 	if (y > 0 && (int)ft_strlen(map->tab[y - 1]) >= (int)ft_strlen(map->tab[y]))
// 		if (map->tab[y - 1][x] != '1')
// 			render_rect(data, &data->game, wall);
// 	if (y < map->hgt && (int)ft_strlen(map->tab[y + 1]) >= x + 1)
// 		if (map->tab[y + 1][x] != '1')
// 			render_rect(data, &data->game, wall);
// }

// static void	render_player(t_data *data)
// {
// 	double	x;
// 	double	y;

// 	x = ((data->player.x / CELL_SIZE) * 7) + 8;
// 	y = ((data->player.y / CELL_SIZE) * 7) + 8;
// 	render_rect(data, &data->game, (t_rect){x, y, 4, 4, RED});
// }

void	render_mini_map(t_data *data)
{
	int		x;
	int		y;

	get_player_config(&data->player, &data->mini_map);
	set_tile_and_walls_specs(&data->mini_map);
	cam_init(&data->map, &data->player, &data->mini_map);
	y = data->mini_map.cam.y;
	while (y < MM_HGT / MM_CELL_SIZE)
	{
		x = data->mini_map.cam.x;
		while (x < MM_WDTH / MM_CELL_SIZE)
		{
			data->mini_map.tile.x = (x * MM_CELL_SIZE) + 10;
			data->mini_map.tile.y = (y * MM_CELL_SIZE) + 10;
			if (data->map.tab[y][x] != '1')
				render_rect(data, &data->game, data->mini_map.tile);
			else
				render_wall(data, &data->map, x, y);
			x ++;
		}
		y ++;
	}
	render_rect(data, &data->game, data->mini_map.player);
}

static void	render_wall(t_data *data, t_map *map, int x, int y)
{
	data->mini_map.wall.x = (x * MM_CELL_SIZE) + 10;
	data->mini_map.wall.y = (y * MM_CELL_SIZE) + 10;
	if (x > 0 && map->tab[y][x - 1] != '1')
		render_rect(data, &data->game, data->mini_map.wall);
	if (x < (int)ft_strlen(map->tab[y]) && map->tab[y][x + 1] != '1')
		if (map->tab[y][x + 1] != '1' && map->tab[y][x + 1] != 0)
			render_rect(data, &data->game, data->mini_map.wall);
	if (y > 0 && (int)ft_strlen(map->tab[y - 1]) >= (int)ft_strlen(map->tab[y]))
		if (map->tab[y - 1][x] != '1')
			render_rect(data, &data->game, data->mini_map.wall);
	if (y < map->hgt && (int)ft_strlen(map->tab[y + 1]) >= x + 1)
		if (map->tab[y + 1][x] != '1')
			render_rect(data, &data->game, data->mini_map.wall);
}

static void	get_player_config(t_player *player, t_mini_map *mini_map)
{
	mini_map->player.x = ((player->x / CELL_SIZE) * MM_CELL_SIZE) + 10;
	mini_map->player.y = ((player->y / CELL_SIZE) * MM_CELL_SIZE) + 10;
	mini_map->player.wdth = MM_CELL_SIZE;
	mini_map->player.hgt = MM_CELL_SIZE;
	mini_map->player.color = RED;
}

static void	set_tile_and_walls_specs(t_mini_map *mini_map)
{
	mini_map->tile.wdth = MM_CELL_SIZE;
	mini_map->tile.hgt = MM_CELL_SIZE;
	mini_map->tile.color = WHITE;
	mini_map->wall.wdth = MM_CELL_SIZE;
	mini_map->wall.hgt = MM_CELL_SIZE;
	mini_map->wall.color = BLACK;
}

static void	cam_init(t_map *map, t_player *player, t_mini_map *mini_map)
{
	(void)map;
	mini_map->cam.y = ((player->y / CELL_SIZE) * MM_CELL_SIZE) + 10 - (5 * MM_CELL_SIZE);
	mini_map->cam.x = ((player->x / CELL_SIZE) * MM_CELL_SIZE) + 10 - (5 * MM_CELL_SIZE);

	// printf("player_x = %f\n", ((player->x / CELL_SIZE) * MM_CELL_SIZE) + 10);
	// printf("player_y = %f\n", ((player->y / CELL_SIZE) * MM_CELL_SIZE) + 10);
	if (mini_map->cam.y < 0)
		mini_map->cam.y = 0;
	if (mini_map->cam.x < 0)
		mini_map->cam.x = 0;
	if (mini_map->cam.y + MM_HGT > MM_HGT)
		mini_map->cam.y = 0;
	if (mini_map->cam.x + MM_WDTH > MM_WDTH)
		mini_map->cam.x = 0;
	// printf("cam_x = %f\n", ((player->x / CELL_SIZE) * MM_CELL_SIZE) + 10 - (5 * MM_CELL_SIZE));
	// printf("cam_y = %f\n", ((player->y / CELL_SIZE) * MM_CELL_SIZE) + 10 - (5 * MM_CELL_SIZE));
}