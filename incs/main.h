/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:24:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/07 15:43:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The main.h file is where we :
	- include user-defined header files,
	- declare our main function.
*/

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
# include "init_images.h"
# include "init_player.h"
# include "key_press.h"
# include "render_manager.h"
# include "config_parser.h"
# include "utils.h"
# include "window_manager.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* main/main.c */
int		main(int ac, char **av);
void	render_world(t_data *data, t_config *config, t_win *win);

#endif
