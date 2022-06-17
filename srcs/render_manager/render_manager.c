/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:36:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/07 09:48:15 by llethuil         ###   ########lyon.fr   */
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

void	render_manager(t_data *data)
{
	render_mini_map(data);
	ray_casting(data);
	mlx_put_image_to_window(data->win.mlx, data->win.edge, data->mini_map.ptr, 0, 0);
}
