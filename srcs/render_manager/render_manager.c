/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:54:09 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/24 11:13:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The render_manager.c file is where we :
	- initialize the mini_map image.
	- add pixels to the image that correspond to:
		- the map
		- the player position
		- the rays
	- put the mini_map imge to the window
*/

#include "main.h"

void	render_manager(t_data *data, t_win *win)
{
	ray_casting(data);
	render_game(data, &data->player, data->ray_tab);
	render_mini_map(data);
	mlx_put_image_to_window(win->mlx, win->edge, data->game.ptr, 0, 0);
}
