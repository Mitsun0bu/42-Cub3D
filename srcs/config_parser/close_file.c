/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:34:16 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:34:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The close_file.c file is where we close the '.cub' file
	selected by the user.
*/

#include "main.h"

void	close_file(int fd)
{
	if (close(fd) == -1)
	{
		printf("Error !\n");
		printf("Map closing failed !\n");
		exit (0);
	}
}