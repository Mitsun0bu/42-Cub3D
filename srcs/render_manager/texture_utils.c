/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:11 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 16:27:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_texture	get_texture(t_data *data, int i)
{
	if (data->player.orientation == 'N')
	{
		if (data->ray_tab[i].grid_hit == HORIZONTAL)
		{
			return (data->so_tex);
		}
		else
		{
			if (data->player.x > data->ray_tab[i].wall_hit_x)
				return (data->ea_tex);
			else
				return (data->we_tex);
		}
	}
	else if (data->player.orientation == 'S')
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
	else if (data->player.orientation == 'E')
	{
		if (data->ray_tab[i].grid_hit == VERTICAL)
		{
			return (data->we_tex);
		}
		else
		{
			if (data->player.y > data->ray_tab[i].wall_hit_y)
				return (data->so_tex);
			else
				return (data->no_tex);
		}
	}
	else if (data->player.orientation == 'W')
	{
		if (data->ray_tab[i].grid_hit == VERTICAL)
		{
			return (data->ea_tex);
		}
		else
		{
			if (data->player.y < data->ray_tab[i].wall_hit_y)
				return (data->no_tex);
			else
				return (data->so_tex);
		}
	}
	return (data->so_tex);
}

int	get_tex_color(t_texture *texture, t_coord *coord)
{
	if (coord->x >= 0 && coord->x < texture->wdth && coord->y >= 0 && coord->y < texture->hgt)
	{
		return (*(int *)(texture->ptr + (4 * texture->wdth * (int)coord->y) + (4 * (int)coord->x)));
	}
	return (FAILED);
}