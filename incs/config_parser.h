/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:25:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:25:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The config_parser.h file is where we declare functions
	which help us to get the specifications from the .cub file
	selected by the user and found in maps folder.
	The specifications are :
	- the textures paths,
	- the floor and ceiling colors,
	- the map.
*/

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_PARSER_H
# define CONFIG_PARSER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */


/*	config_parser/check_map.c												*/
void	check_map(t_data *data);
/*	config_parser/check_texture_paths.c										*/
void	check_texture_paths(t_config *config);
/*	config_parser/close_file.c												*/
void	close_file(int fd);
/*	config_parser/convert_rgb_codes_to_hex.c								*/
void	convert_rgb_codes_to_hex(t_config *config);
/*	config_parser/exit_with_error_message.c									*/
void	exit_with_error_message(int err_type, int err_no);
/*	config_parser/get_map.c													*/
void	get_map(t_map *map, int fd);
/*	config_parser/get_rgb_code_int_tabs.c									*/
void	get_rgb_code_int_tabs(t_config *config);
/*	config_parser/get_config_lines.c										*/
void	get_config_lines(t_config *config, int fd);
/*	config_parser/open_file.c												*/
int		open_file(int ac, char **av);
/*	config_parser/parse_config_line.c										*/
void	parse_config_lines(t_config *config);
/*	config_parser/config_parser.c											*/
void	config_parser(int ac, char **av, t_data *data);
/*	config_parser/replace_spaces_in_map.c									*/
void	replace_spaces_in_map(t_map *map);
/*	config_parser/replace_spaces_in_str.c									*/
void	replace_spaces_in_str(char *str, char c);

#endif