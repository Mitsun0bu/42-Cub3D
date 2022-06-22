/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 12:13:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	render_wall(t_data *data, t_map *map, int x, int y);

void	render_mini_map(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->map.hgt)
	{
		x = -1;
		while (++x < (int)ft_strlen(data->map.tab[y]))
		{
			if (data->map.tab[y][x] != '1')
				render_rect(data, &data->walls,
					(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0xFFFFFF});
			else
				render_wall(data, &data->map, x, y);
		}
	}
	render_player(data);
}

static void	render_wall(t_data *data, t_map *map, int x, int y)
{
	if (x > 0 && map->tab[y][x - 1] != '1')
		render_rect(data, &data->walls,
			(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
	if (x < (int)ft_strlen(map->tab[y]) && map->tab[y][x + 1] != '1')
		if (map->tab[y][x + 1] != '1' && map->tab[y][x + 1] != 0)
			render_rect(data, &data->walls,
				(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
	if (y > 0 && (int)ft_strlen(map->tab[y - 1]) >= (int)ft_strlen(map->tab[y]))
		if (map->tab[y - 1][x] != '1')
			render_rect(data, &data->walls,
				(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
	if (y < map->hgt && (int)ft_strlen(map->tab[y + 1]) >= x + 1)
		if (map->tab[y + 1][x] != '1')
			render_rect(data, &data->walls,
				(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
}

void	render_player(t_data *data)
{
	double	x;
	double	y;

	x = ((data->player.x / 64) * 7) + 8;
	y = ((data->player.y / 64) * 7) + 8;
	render_rect(data, &data->walls, (t_rect){x, y, 2, 2, 0xFFFF00});
}
