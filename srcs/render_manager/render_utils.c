/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:47:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/16 12:07:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	render_rect(t_data *data, t_img *render, t_rect rect)
{
	int	i;
	int	j;

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

int render_circle(t_data *data, t_img *render, t_circle circle)
{
	double	i;
	double	angle;
	double	x;
	double	y;

	if (data->win.edge == NULL)
		return (1);
	i = 0;
	while (i < 360)
    {
        angle = i;
        x = circle.radius * cos(angle * M_PI / 180);
        y = circle.radius * sin(angle * M_PI / 180);
        pixel_put(render, circle.x + x, circle.y + y, circle.color);
		i += 0.1;
    }
	return (0);
}

int	get_pixel_color_from_texture(t_texture *texture, t_coord *coord)
{
	if (coord->x >= 0 && coord->x < texture->wdth && coord->y >= 0 && coord->y < texture->hgt)
		return (*(int*)(texture->ptr + (4 * texture->wdth * (int)coord->y) + (4 * (int)coord->x)));
	return (0xFFE436);
}