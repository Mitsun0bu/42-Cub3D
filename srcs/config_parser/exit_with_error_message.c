/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error_message.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:34:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:35:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The exit_with_error_message.c file is where we select the error message
	to print depending on the error that occured during the parsing.
*/

#include "main.h"

static void	print_open_err_message(int err_no);
static void	print_config_err_message(int err_no);
static void print_map_err_message(int err_no);

void	exit_with_error_message(int err_type, int err_no)
{
	printf("Error!\n");
	if (err_type == open_err)
		print_open_err_message(err_no);
	else if (err_type == config_err)
		print_config_err_message(err_no);
	else if (err_type == map_err)
		print_map_err_message(err_no);
	exit(0);
}

static void	print_open_err_message(int err_no)
{
	if (err_no == n_arg)
	{
		printf("Wrong number of arguments !\n");
		printf("Usage : ./cub3d <map_name>.cub\n");
	}
	else if (err_no == extension)
	{
		printf("Wrong extension!\n");
		printf("Usage : ./cub3d <map_name>.cub\n");
	}
	else if (err_no == dir)
	{
		printf("<map_name>.cub is a directory !");
		printf("Usage : ./cub3d <map_name>.cub\n");
	}
	else if (err_no == fail)
		printf("Map opening failed !\n");
}

static void	print_config_err_message(int err_no)
{
	if (err_no == n_arg)
		printf("Missing specification(s) in map file !\n");
	else if (err_no == invalid)
		printf("Invalid specification(s) in map file !\n");
	else if(err_no == extension)
		printf("Format of texture files must be '.xpm'\n");
	printf("Usage :\n");
	printf("NO\t./<path_to_the_north_texture>.xpm\n");
	printf("SO\t./<path_to_the_south_texture>.xpm\n");
	printf("WE\t./<path_to_the_west_texture>.xpm\n");
	printf("EA\t./<path_to_the_east_texture>.xpm\n");
	printf("F\tR,G,B\nC\tR,G,B\n");
	printf("(where R, G and B are integers between 0 and 255)\n");
}

static void print_map_err_message(int err_no)
{
	if (err_no == missing)
		printf("Map is missing in the map file!\n");
	else if (err_no == new_line)
		printf("New line is forbidden in the map!\n");
	else if (err_no == invalid)
		printf("Invalid character in the map !\n");
	else if (err_no == n_player)
		printf("Map must have one starting position for the player!\n");
	else if (err_no == walls)
		printf("Map must be surrounded by walls !\n");
}