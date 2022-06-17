/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 17:56:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The main.c file is where we :
	- initialize our data structure,
	- get the specifications,
*/

#include "main.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	config_parser(ac, av, &data);
	data.map.cell_size = 64;
	window_manager(&data);
	init_images(&data, &data.config);
	init_player(&data, &data.player, &data.config);
	init_ray_tab(&data);
	render_manager(&data);
	mlx_hook(data.win.edge, 2, 0, key_press, &data);
	mlx_loop(data.win.mlx);
	exit (0);
}
