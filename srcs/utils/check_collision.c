/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:33:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 15:36:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_collision(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;
	int	x_max;
	int	y_max;

	map_x = floor(x / data->map.cell_size);
	map_y = floor(y / data->map.cell_size);
	x_max = (int)ft_strlen(data->map.tab[map_y]);
	y_max = data->win.hgt / data->map.cell_size;
	if (map_y <= 0 ||map_y > y_max || map_x <= 0 || map_x > x_max)
		return (SUCCESS);
	if (data->map.tab[map_y][map_x] == '1')
		return (SUCCESS);
	return (FAILED);
}