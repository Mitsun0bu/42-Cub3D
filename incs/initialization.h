/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:15:54 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 18:22:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	init_img/init_img.c														  */
void	init_img(t_data *data, t_config *config, t_img *mini_map, t_img *walls);

/*	init_player/init_player.c												  */
void	init_player(t_player *player, t_config *config);

/*	init_ray_tab/init_ray_tab.c												  */
int		init_ray_tab(t_data *data);

#endif