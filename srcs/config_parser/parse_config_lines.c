/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:33:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The parse_config_line.c file is where we :
	- check the validity of all specification lines
	- copy the important part of the line in the config structure.
*/

#include "main.h"

static char	*parse_a_spec(char *str, char c);
static int	skip_spaces(char *str, int *i);
static char	*copy_path(char *str, int i_start);
static char	*copy_color(char *str, int i_start);

void	parse_config_lines(t_config *config)
{
	config->no_texture_path = parse_a_spec(config->no_texture_path, 'O');
	config->so_texture_path = parse_a_spec(config->so_texture_path, 'O');
	config->we_texture_path = parse_a_spec(config->we_texture_path, 'E');
	config->ea_texture_path = parse_a_spec(config->ea_texture_path, 'A');
	config->floor_rgb_str = parse_a_spec(config->floor_rgb_str, ' ');
	config->ceiling_rgb_str = parse_a_spec(config->ceiling_rgb_str, ' ');
}

static char	*parse_a_spec(char *str, char c)
{
	int		i_start;
	char	*spec;

	i_start = 2;
	spec = NULL;
	if (str[1] != c)
		exit_with_error_message(config_err, invalid);
	replace_spaces_in_str(str, ' ');
	i_start = skip_spaces(str, &i_start);
	if (c != ' ')
		spec = copy_path(str, i_start);
	else
		spec = copy_color(str, i_start);
	return (spec);
}

static int	skip_spaces(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++ ;
	return (*i);
}

static char	*copy_path(char *str, int i_start)
{
	char	*path;

	path = NULL;
	if (str[i_start] && str[i_start] == '.' && str[i_start + 1] == '/')
	{
		path = ft_strdup(str + i_start);
		path[ft_strlen(path) - 1] = '\0';
		free(str);
		return (path);
	}
	exit_with_error_message(config_err, invalid);
	return (NULL);
}

static char	*copy_color(char *str, int i_start)
{
	char	*color;
	int		i;

	color = NULL;
	i = i_start;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == FAILED && !ft_strchr(" ,", str[i]))
			exit_with_error_message(config_err, invalid);
		i ++;
	}
	color = ft_strdup(str + i_start);
	free(str);
	return (color);
}
