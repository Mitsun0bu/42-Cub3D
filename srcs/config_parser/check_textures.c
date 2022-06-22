/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:01:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 18:01:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The check_texture_paths.c file is where we check that
	the extension of all the textures is '.xpm'.
*/

#include "main.h"

static void	check_a_texture(char *str);

void	check_textures(t_config *config)
{
	check_a_texture(config->no_texture_path);
	check_a_texture(config->so_texture_path);
	check_a_texture(config->we_texture_path);
	check_a_texture(config->ea_texture_path);
}

static void	check_a_texture(char *str)
{
	int	fd;
	int	i_extension;

	i_extension = ft_strlen(str) - 4;
	if (ft_strnstr(str + i_extension, ".xpm", 4) == NULL)
		exit_with_error_message(config_err, extension);
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
		exit_with_error_message(config_err, dir);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_with_error_message(config_err, fail);
	close(fd);
}
