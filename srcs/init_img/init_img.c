/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:21:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 15:21:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_img(t_data *data, t_config *config, t_img *mini_map, t_img *walls)
{
	mini_map->ptr = mlx_new_image(data->win.mlx, 1920, 1080);
	mini_map->addr = mlx_get_data_addr(mini_map->ptr,
			&mini_map->bpp, &mini_map->line_len, &mini_map->endian);
	walls->ptr = mlx_new_image(data->win.mlx, data->win.wdth, data->win.hgt);
	walls->addr = mlx_get_data_addr(walls->ptr,
			&walls->bpp, &walls->line_len, &walls->endian);
	data->ea_tex.tex = mlx_xpm_file_to_image(data->win.mlx,
			config->ea_texture_path, &data->ea_tex.wdth, &data->ea_tex.hgt);
	data->ea_tex.ptr = mlx_get_data_addr(data->ea_tex.tex,
			&data->ea_tex.bpp, &data->ea_tex.line_len, &data->ea_tex.endian);
	data->no_tex.tex = mlx_xpm_file_to_image(data->win.mlx,
			config->no_texture_path, &data->no_tex.wdth, &data->no_tex.hgt);
	data->no_tex.ptr = mlx_get_data_addr(data->no_tex.tex,
			&data->no_tex.bpp, &data->no_tex.line_len, &data->no_tex.endian);
	data->so_tex.tex = mlx_xpm_file_to_image(data->win.mlx,
			config->so_texture_path, &data->so_tex.wdth, &data->so_tex.hgt);
	data->so_tex.ptr = mlx_get_data_addr(data->so_tex.tex,
			&data->so_tex.bpp, &data->so_tex.line_len, &data->so_tex.endian);
	data->we_tex.tex = mlx_xpm_file_to_image(data->win.mlx,
			config->we_texture_path, &data->we_tex.wdth, &data->we_tex.hgt);
	data->we_tex.ptr = mlx_get_data_addr(data->we_tex.tex,
			&data->we_tex.bpp, &data->we_tex.line_len, &data->we_tex.endian);
}
