/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/27 17:43:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_mini_map_y(t_map *map, t_player *player, t_mini_map *mini_map);
static void	init_mini_map_x(t_map *map, t_player *player, t_mini_map *mini_map);

void	render_mini_map(t_data *d, t_map *m, t_player *p, t_mini_map *mm)
{
	d->mini_map.square.wdth = MM_CELL_SIZE;
	d->mini_map.square.hgt = MM_CELL_SIZE;
	init_mini_map_y(&d->map, &d->player, &d->mini_map);
	while (mm->y < (int)floor(p->y / CELL_SIZE) + mm->y_max
		&& mm->y < m->hgt)
	{
		init_mini_map_x(&d->map, &d->player, &d->mini_map);
		while (mm->x < (int)floor(p->x / CELL_SIZE) + mm->x_max
			&& mm->x < (int)ft_strlen(m->tab[mm->y]))
		{
			if (d->map.tab[mm->y][mm->x] != '1')
				render_rect(d, &d->game, mm->square, WHITE);
			else
				render_rect(d, &d->game, mm->square, BLACK);
			if (mm->y == (int)floor(p->y / CELL_SIZE)
				&& mm->x == (int)floor(p->x / CELL_SIZE))
				render_rect(d, &d->game, mm->square, RED);
			mm->x ++;
			mm->square.x += 10;
		}
		mm->y ++;
		mm->square.y += 10;
	}
}

static void	init_mini_map_y(t_map *map, t_player *player, t_mini_map *mini_map)
{
	mini_map->square.y = 10;
	mini_map->y_max = 10;
	mini_map->y = (int)floor(player->y / CELL_SIZE) - mini_map->y_max;
	if ((int)floor(player->y / CELL_SIZE) + mini_map->y_max > map->hgt)
		mini_map->y -= (int)floor(player->y / CELL_SIZE)
			+ mini_map->y_max - map->hgt;
	if (mini_map->y < 0)
	{
		mini_map->y_max -= mini_map->y;
		mini_map->y = 0;
	}
}

static void	init_mini_map_x(t_map *map, t_player *player, t_mini_map *mini_map)
{
	mini_map->square.x = 10;
	mini_map->x_max = 20;
	mini_map->x = (int)floor(player->x / CELL_SIZE) - mini_map->x_max;
	if ((int)floor(player->x / CELL_SIZE) + mini_map->x_max
		> (int)ft_strlen(map->tab[mini_map->y]))
		mini_map->x -= (int)floor(player->x / CELL_SIZE)
			+ mini_map->x_max - (int)ft_strlen(map->tab[mini_map->y]);
	if (mini_map->x < 0)
	{
		mini_map->x_max -= mini_map->x;
		mini_map->x = 0;
	}
}
