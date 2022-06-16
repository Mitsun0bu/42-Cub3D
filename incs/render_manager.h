/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:24:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:25:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MANAGER_H
# define RENDER_MANAGER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	render_manager/ray_casting.c											*/
void	ray_casting(t_data *data);
double	normalize_angle(double angle);
void	dda_algorithm(t_data *data);
void	get_ray_orientation(t_player *player, t_ray *ray);
void		find_horizontal_wall_hit(t_data *data);
void	find_vertical_wall_hit(t_data *data);
void	get_grid_intercept(t_map *map, t_player *player, t_ray *ray, int grid);
void	get_grid_step(t_map *map, t_ray *ray, int grid);
void		find_wall_hit(t_data *data, int grid);
void	get_next_grid_touch(t_ray *ray, int grid);
void		horizontal_wall_hit_loop(t_data *data, t_win *win, t_player *player, t_ray *ray);
void		vertical_wall_hit_loop(t_data *data, t_win *win, t_player *player, t_ray *ray);


/*	render_manager/render_env.c										*/
void	render_env(t_data *data, int i_ray, double ray_angle, double ray_step);
void	render_ceiling(t_data *data, int i_ray, double column_hgt);
void	render_floor(t_data *data, int i_ray, double column_hgt);
// void	render_walls(t_data *data, int i_ray, t_vector ray, double column_hgt);

/*	render_manager/render_manager.c											*/
void	render_manager(t_data *data);

/*	render_manager/render_mini_map.c										*/
void	render_mini_map(t_data *data);
void	render_walls_and_tiles(t_data *data, int x, int y);
void	render_player(t_data *data);

/*	render_manager/render_utils.c											*/
int     render_rect(t_data *data, t_img *render, t_rect rect);
int	    render_line(t_data *data, t_img *render, t_line line);
int     render_circle(t_data *data, t_img *render, t_circle circle);
int		get_pixel_color_from_texture(t_texture *texture, t_coord *coord);

#endif