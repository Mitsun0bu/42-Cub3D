/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:46:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 12:46:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float calculate_distance(float x1, float y1, float x2, float y2)
{
	float	distance;

	distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (distance);
}
