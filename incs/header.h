/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:22:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 17:52:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The header.h file is where we :
	- include pre-existing header files,
	- define our macros and enums,
	- declare typedefs for our structures.
*/

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ ENUMS ~~~                                */
/*                                                                            */
/* ************************************************************************** */

enum e_result {
	SUCCESS,
	FAILED
};

enum e_found {
	FOUND,
	NOT_FOUND
};

enum e_err_type {
	open_err,
	config_err,
	map_err
};

enum e_err_no {
	n_arg,
	extension,
	dir,
	fail,
	missing,
	invalid,
	new_line,
	n_player,
	walls
};

enum e_check {
	YES,
	NO
};

enum e_key {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	left_arrow = 123,
	right_arrow = 124
};

enum e_color {
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	GREY = 0xE0E0E0,
	RED = 0xFF0000,
	PINK = 0xFF99FF,
	YELLOW = 0xFFFF66
};

enum e_orientation {
	NE,
	NW,
	SW,
	SE
};

enum e_grid {
	HORIZONTAL,
	VERTICAL
};

enum e_dimensions {
	WIN_WDTH = 1720,
	WIN_HGT = 960,
	CELL_SIZE = 64
};

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_config
{
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	char	*floor_rgb_str;
	char	*ceiling_rgb_str;
	int		*floor_rgb_int_tab;
	int		*ceiling_rgb_int_tab;
	int		floor_hex_code;
	int		ceiling_hex_code;
	char	player_orientation;
}	t_config;

typedef struct map
{
	char	**tab;
	int		hgt;
	int		wdth;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*edge;
	void	*img_ptr;
	int		x;
	int		y;
}	t_win;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_tex
{
	char	*path;
	void	*tex;
	int		wdth;
	int		hgt;
	void	*ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_rect
{
	int	x;
	int	y;
	int	wdth;
	int	hgt;
	int	color;
}	t_rect;

typedef struct s_line
{
	double	x_start;
	double	y_start;
	double	x_end;
	double	y_end;
	int		color;
}	t_line;

typedef struct s_circle
{
	int	x;
	int	y;
	int	radius;
	int	color;
}	t_circle;

typedef struct s_player
{
	double	x;
	double	y;
	int		radius;
	char	orientation;
	int		turn_direction;
	int		walk_dir;
	double	rot_angle;
	double	move_speed;
	double	rotation_speed;
	double	fov;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	dist;
	int		orientation;
	double	wall_hit_x;
	double	wall_hit_y;
	int		horizontal_wall_hit;
	int		vertical_wall_hit;
	int		grid_hit;
	t_line	line;
}	t_ray;

typedef struct s_probe
{
	double	angle;
	int		orientation;
	double	x_intcp;
	double	y_intcp;
	double	x_step;
	double	y_step;
	double	wall_hit_x;
	double	wall_hit_y;
	double	next_hit_x;
	double	next_hit_y;
	int		horizontal_wall_hit;
	int		vertical_wall_hit;
	int		grid_hit;
	double	len;
}	t_probe;

typedef struct s_data
{
	t_config	config;
	t_map		map;
	t_win		win;
	t_player	player;

	int			n_rays;
	int			wall_strip_wdth;
	t_ray		*ray_tab;

	t_img		mini_map;
	t_img		walls;

	t_tex		ea_tex;
	t_tex		no_tex;
	t_tex		so_tex;
	t_tex		we_tex;
}	t_data;

#endif
