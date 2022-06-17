/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:39:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 10:10:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	init_ray(t_data *data, t_ray *ray)
// {
	// ray->wall_strip_wdth = 1;
	// ray->n_rays = data->win.wdth / ray->wall_strip_wdth;
	// data->ray_tab = malloc(sizeof(t_ray) * data->n_rays);
	// if (!data->ray_tab)
	// {
	// 	printf("Error : Malloc of ray_tab failed !");
	// 	return (FAILED);
	// }
// }

int	init_ray_tab(t_data *data)
{
	data->wall_strip_wdth = 1;
	data->n_rays = data->win.wdth / data->wall_strip_wdth;
	data->ray_tab = malloc(sizeof(t_ray) * data->n_rays);
	if (!data->ray_tab)
	{
		printf("Error : Malloc of ray_tab failed !");
		return (FAILED);
	}
	return (SUCCESS);
}