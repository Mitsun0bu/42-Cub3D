/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:20 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/14 10:16:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The pixel_put function is a utils function that:
	- takes a pointer to the image to render,
	(x,y) coordinates
	and a color code as parameters.
	- put pixel of the given color, at the given coordinate in the given image.
*/

#include "main.h"

void	pixel_put(t_img *render, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * render->line_len + x * (render->bpp / 8));
	dst = render->addr + offset;
	*(unsigned int*)dst = color;
}
