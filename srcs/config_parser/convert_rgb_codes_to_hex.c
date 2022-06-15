/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_codes_to_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:06:35 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:35:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The get_rgb_code_int_tabs.c file is where we :
	- check that the floor_rgb_str and ceiling_rgb_str
	are made of 3 components (R,G and B) separated by one comma ','.
	- split the floor_rgb_str and ceiling_rgb_str components at the ','.
	- clean each color component, removing spaces.
	- convert char* color components into int.
	- check that each int color component are between 0 and 255.
*/

#include "main.h"

static int	convert_rgb_to_hex(int *rgb_color_code);

void	convert_rgb_codes_to_hex(t_config *config)
{
	config->floor_hex_code = convert_rgb_to_hex(config->floor_rgb_int_tab);
	config->ceiling_hex_code = convert_rgb_to_hex(config->ceiling_rgb_int_tab);
}

static int	convert_rgb_to_hex(int *rgb_int_tab)
{
	int	color;
	int	i;
	int	hex_code;

	color = 0;
	hex_code = 0;
	i = -1;
	while (++i < 3)
	{
		rgb_int_tab[i] = color | (rgb_int_tab[i] << (16 - (i * 8)));
		hex_code += rgb_int_tab[i];
	}
	return (hex_code);
}