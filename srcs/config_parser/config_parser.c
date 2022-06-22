/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 18:00:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The config_parser.c file is where we :
	- open the '.cub' file that has been selected by the user,
	- initialize our 'config' structure with the data stored in the '.cub' file,
	- close the '.cub' file,
	- parse the data we have extracted from the '.cub' file.
*/

#include "main.h"

void	config_parser(int ac, char **av, t_data *data)
{
	int	fd;

	fd = open_file(ac, av);
	get_config_lines(&data->config, fd);
	get_map(&data->map, fd);
	close_file(fd);
	replace_spaces_in_map(&data->map);
	check_map(data);
	parse_config_lines(&data->config);
	check_textures(&data->config);
	get_rgb_code_int_tabs(&data->config);
	convert_rgb_codes_to_hex(&data->config);
}
