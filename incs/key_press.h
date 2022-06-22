/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:23:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 16:59:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESS_H
# define KEY_PRESS_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	key_press/key_press.c													  */
int		key_press(int key, t_data *data);

/*	key_press/movement.c													  */
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/*	key_press/rotation.c													  */
void	turn_left(t_player *player);
void	turn_right(t_player *player);

/* key_press/utils_movement.c												  */
void	update_up_down_pos(t_data *data, t_player *player, double move_step);
void	update_left_right_pos(t_data *data, t_player *player, double move_step);

#endif
