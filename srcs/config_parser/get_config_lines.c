/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:33:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The get_config_lines.c file is where we :
	- check that the config (north, south, west and east texture paths
	+ floor and ceiling colors) are all found in the '.cub' file.
	- check if a line start with an valid character (N,S,W,E,F or C)
	- copy the line in the 'config' structure.
	However, we do not check if the rest of the entire spec line is valid here.
*/

#include "main.h"

static int	check_config_finding(t_config *config);
static void	copy_config_line(t_config *config, char *line);

void	get_config_lines(t_config *config, int fd)
{
	char			*line;
	char			*trimmed_line;

	while (check_config_finding(config) == not_found)
	{
		line = ft_get_next_line(fd);
		if (!line)
			exit_with_error_message(config_err, missing);
		trimmed_line = ft_strtrim(line, "\t\v\f\r ");
		if (ft_strchr("NSWEFC", trimmed_line[0]))
			copy_config_line(config, trimmed_line);
		else if (!ft_strchr("\n", line[0]))
		{
			free(trimmed_line);
			exit_with_error_message(config_err, invalid);
		}
		free(line);
		free(trimmed_line);
	}
}

static int	check_config_finding(t_config *config)
{
	int	i_texture_path;
	int	i_color;

	i_texture_path = 0;
	i_color = 0;
	if (config->no_texture_path)
		i_texture_path ++;
	if (config->so_texture_path)
		i_texture_path ++;
	if (config->we_texture_path)
		i_texture_path ++;
	if (config->ea_texture_path)
		i_texture_path ++;
	if (config->floor_rgb_str)
		i_color ++;
	if (config->ceiling_rgb_str)
		i_color ++;
	if (i_texture_path == 4 && i_color == 2)
		return (found);
	else
		return (not_found);
}

static void	copy_config_line(t_config *config, char *line)
{
	if (line[0] == 'N' && !config->no_texture_path)
		config->no_texture_path = ft_strdup(line);
	else if (line[0] == 'S' && !config->so_texture_path)
		config->so_texture_path = ft_strdup(line);
	else if (line[0] == 'W' && !config->we_texture_path)
		config->we_texture_path = ft_strdup(line);
	else if (line[0] == 'E' && !config->ea_texture_path)
		config->ea_texture_path = ft_strdup(line);
	else if (line[0] == 'F' && !config->floor_rgb_str)
		config->floor_rgb_str = ft_strdup(line);
	else if (line[0] == 'C' && !config->ceiling_rgb_str)
		config->ceiling_rgb_str = ft_strdup(line);
	else
	{
		free(line);
		exit_with_error_message(config_err, invalid);
	}
}
