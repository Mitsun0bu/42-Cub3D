/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:34:20 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:35:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The check_texture_paths.c file is where we check that
	the extension of all the textures is '.xpm'.
*/

#include "main.h"

static void	check_texture_extension(char *str);

void	check_texture_paths(t_config *config)
{
	check_texture_extension(config->no_texture_path);
	check_texture_extension(config->so_texture_path);
	check_texture_extension(config->we_texture_path);
	check_texture_extension(config->ea_texture_path);
}

static void	check_texture_extension(char *str)
{
	int	i_extension;

	i_extension = ft_strlen(str) - 4;
	if (ft_strnstr(str + i_extension, ".xpm", 4) == NULL)
		exit_with_error_message(config_err, extension);
}
