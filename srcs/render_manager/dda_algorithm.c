/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:38:33 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/20 15:43:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	dda_algorithm(t_data *data, double ray_angle, int column_i)
{
	t_probe	h_probe;
	t_probe	v_probe;

	ray_angle = normalize_angle(ray_angle);
	init_h_probe(&data->map, &data->player, ray_angle, &h_probe);
	find_h_probe_wall_hit(data, &data->win, &h_probe);
	init_v_probe(&data->map, &data->player, ray_angle, &v_probe);
	find_v_probe_wall_hit(data, &data->win, &v_probe);
	get_probes_len(&data->player, &h_probe, &v_probe);
	update_ray(&data->ray_tab[column_i], ray_angle, &h_probe, &v_probe);
}
