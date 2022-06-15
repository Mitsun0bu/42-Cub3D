/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:31:16 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:31:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_to_malloc(long int nbr_int, int sign);

char	*ft_itoa(int n)
{
	long int	nbr_int;
	int			sign;
	char		*nbr_str;
	int			i;

	nbr_int = n;
	sign = 1;
	if (nbr_int < 0)
	{
		nbr_int = nbr_int * -1;
		sign = -1;
	}
	nbr_str = malloc(sizeof(char) * (len_to_malloc(nbr_int, sign) + 1));
	if (nbr_str == NULL)
		return (0);
	i = len_to_malloc(nbr_int, sign);
	nbr_str[i] = '\0';
	while (--i >= 0)
	{
		nbr_str[i] = (nbr_int % 10) + '0';
		nbr_int = nbr_int / 10;
	}
	if (sign < 0)
		nbr_str[0] = '-';
	return (nbr_str);
}

static int	len_to_malloc(long int nbr_int, int sign)
{
	int	len_to_malloc;

	len_to_malloc = 0;
	if (sign < 0)
		len_to_malloc++;
	if (nbr_int == 0)
		len_to_malloc++;
	while (nbr_int > 0)
	{
		nbr_int = nbr_int / 10;
		len_to_malloc++;
	}
	return (len_to_malloc);
}
