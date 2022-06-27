/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:13:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/27 17:18:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	render_rect(t_data *data, t_img *render, t_rect rect, int color)
{
	int	i;
	int	j;

	rect.color = color;
	if (data->win.edge == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.hgt)
	{
		j = rect.x;
		while (j < rect.x + rect.wdth)
		{
			pixel_put(render, j, i, rect.color);
			j ++;
		}
		i++;
	}
	return (0);
}

int	render_line(t_data *data, t_img *render, t_line line)
{
	double	dx;
	double	dy;
	int		n_pixels;
	double	x;
	double	y;

	if (data->win.edge == NULL)
		return (1);
	dx = line.x_end - line.x_start;
	dy = line.y_end - line.y_start;
	n_pixels = sqrt((dx * dx) + (dy * dy));
	dx /= n_pixels;
	dy /= n_pixels;
	x = line.x_start;
	y = line.y_start;
	while (n_pixels)
	{
		pixel_put(render, x, y, line.color);
		x += dx;
		y += dy;
		n_pixels--;
	}
	return (0);
}

int	get_pixel_color_from_texture(t_tex *texture, t_coord *coord)
{
	if (coord->x >= 0 && coord->x < texture->wdth
		&& coord->y >= 0 && coord->y < texture->hgt)
		return (*(int *)(texture->ptr
			+ (4 * texture->wdth * (int)coord->y) + (4 * (int)coord->x)));
	return (0xFFE436);
}
