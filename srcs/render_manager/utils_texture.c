/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 18:14:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_tex	get_north_texture(t_data *data, int i);
static t_tex	get_south_texture(t_data *data, int i);
static t_tex	get_east_tex(t_data *data, int i);
static t_tex	get_west_tex(t_data *data, int i);

t_tex	get_tex(t_data *data, int i)
{
	if (data->player.orientation == 'N')
	{
		return (get_north_texture(data, i));
	}
	else if (data->player.orientation == 'S')
	{
		return (get_south_texture(data, i));
	}
	else if (data->player.orientation == 'E')
	{
		return (get_east_tex(data, i));
	}
	else if (data->player.orientation == 'W')
	{
		return (get_west_tex(data, i));
	}
	return (data->so_tex);
}

static t_tex	get_north_texture(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == HORIZONTAL)
		return (data->so_tex);
	else
	{
		if (data->player.x > data->ray_tab[i].wall_hit_x)
			return (data->ea_tex);
		else
			return (data->we_tex);
	}
}

static t_tex	get_south_texture(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == HORIZONTAL)
		return (data->no_tex);
	else
	{
		if (data->player.x < data->ray_tab[i].wall_hit_x)
			return (data->we_tex);
		else
			return (data->ea_tex);
	}
}

static t_tex	get_east_tex(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == VERTICAL)
		return (data->we_tex);
	else
	{
		if (data->player.y > data->ray_tab[i].wall_hit_y)
			return (data->so_tex);
		else
			return (data->no_tex);
	}
}

static t_tex	get_west_tex(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == VERTICAL)
		return (data->ea_tex);
	else
	{
		if (data->player.y < data->ray_tab[i].wall_hit_y)
			return (data->no_tex);
		else
			return (data->so_tex);
	}
}
