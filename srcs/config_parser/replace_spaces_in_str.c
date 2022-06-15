/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_spaces_in_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:33:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
	The replace_spaces_in_str function is a utils function that:
	- takes a string and a single character as parameters.
	- replace str[i] by the char given in parameter if
	any kind of space character is encountered in the string.
*/

void	replace_spaces_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
			str[i] = c;
		i ++;
	}
}