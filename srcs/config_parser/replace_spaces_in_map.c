/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_spaces_in_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/14 10:39:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The replace_spaces_in_map.c file is where we :
	- replace any space character found in the map by a '1'.
*/

#include "main.h"

void	replace_spaces_in_map(t_map *map)
{
	int	i;

	i = 0;
	while(map->tab[i])
	{
		replace_spaces_in_str(map->tab[i], '1');
		i ++;
	}
}
