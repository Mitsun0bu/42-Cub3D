/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:39:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/15 17:05:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_ray(t_data *data, t_ray *ray)
{
	ray->wall_strip_wdth = 1;
	ray->n_rays = data->win.wdth / ray->wall_strip_wdth;
}