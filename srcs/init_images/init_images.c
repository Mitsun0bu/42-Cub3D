/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:44:17 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 17:54:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_images(t_data *data, t_config *config)
{
	(void)config;

	data->mini_map.ptr = mlx_new_image(data->win.mlx, 1920, 1080);
	data->mini_map.addr = mlx_get_data_addr(data->mini_map.ptr, &data->mini_map.bpp, &data->mini_map.line_len, &data->mini_map.endian);

	data->walls.ptr = mlx_new_image(data->win.mlx, data->win.wdth, data->win.hgt);
	data->walls.addr = mlx_get_data_addr(data->walls.ptr, &data->walls.bpp, &data->walls.line_len, &data->walls.endian);

	data->east_texture.tex = mlx_xpm_file_to_image(data->win.mlx, config->ea_texture_path, &data->east_texture.wdth, &data->east_texture.hgt);
	data->east_texture.ptr = mlx_get_data_addr(data->east_texture.tex, &data->east_texture.bpp, &data->east_texture.line_len, &data->east_texture.endian);

	data->north_texture.tex = mlx_xpm_file_to_image(data->win.mlx, config->no_texture_path, &data->north_texture.wdth, &data->north_texture.hgt);
	data->north_texture.ptr = mlx_get_data_addr(data->north_texture.tex, &data->north_texture.bpp, &data->north_texture.line_len, &data->north_texture.endian);

	data->south_texture.tex = mlx_xpm_file_to_image(data->win.mlx, config->so_texture_path, &data->south_texture.wdth, &data->south_texture.hgt);
	data->south_texture.ptr = mlx_get_data_addr(data->south_texture.tex, &data->south_texture.bpp, &data->south_texture.line_len, &data->south_texture.endian);

	data->west_texture.tex = mlx_xpm_file_to_image(data->win.mlx, config->we_texture_path, &data->west_texture.wdth, &data->west_texture.hgt);
	data->west_texture.ptr = mlx_get_data_addr(data->west_texture.tex, &data->west_texture.bpp, &data->west_texture.line_len, &data->west_texture.endian);
}


