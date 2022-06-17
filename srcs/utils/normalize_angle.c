/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:47:22 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/17 12:47:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	normalize_angle(double angle)
{
	double	normalized_angle;

	normalized_angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		normalized_angle = (2 * M_PI) + angle;
	return (normalized_angle);
}
