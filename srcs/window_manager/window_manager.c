/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/14 11:28:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The window_manager.c file is where we :
	- initialize the height and width of the window.
	- generate the window thanks to mlx.
	- close the window if the user click on the red cross.
*/

#include "main.h"

static void	get_window (t_data *data);

void	window_manager(t_data *data)
{
	data->win.wdth = data->map.wdth * data->map.tile_size;
	data->win.hgt = data->map.hgt * data->map.tile_size;
	get_window(data);
	mlx_hook(data->win.edge, 17, 0, close_window, data);
}

static void	get_window (t_data *data)
{
	data->win.mlx = mlx_init();
	data->win.edge = mlx_new_window(data->win.mlx,
			data->win.wdth, data->win.hgt, "CUB3D");
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->win.mlx, data->win.edge);
	exit(0);
}
