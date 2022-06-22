/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 12:04:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The window_manager.c file is where we :
	- initialize the height and width of the window.
	- generate the window thanks to mlx.
	- close the window if the user click on the red cross.
*/

#include "main.h"

void	get_window(t_data *data)
{
	data->win.mlx = mlx_init();
	data->win.edge = mlx_new_window(data->win.mlx, WIN_WDTH, WIN_HGT, "CUB3D");
	mlx_hook(data->win.edge, 17, 0, close_window, data);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->win.mlx, data->win.edge);
	exit(0);
}
