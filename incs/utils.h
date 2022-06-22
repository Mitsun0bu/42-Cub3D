/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:25:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/22 18:24:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	utils/calculate_distance.c												  */
double	calculate_distance(double x1, double y1, double x2, double y2);

/*	utils/check_collision.c													  */
int		check_collision(t_data *data, double x, double y);

/*	utils/normalize_angle.c													  */
double	normalize_angle(double angle);

/*	utils/pixel_put.c														  */
void	pixel_put(t_img *render, int x, int y, int color);

/*	utils/window_manager.c													  */
void	get_window(t_data *data);
int		close_window(t_data *data);

#endif
