/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:29:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:29:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_init;
	size_t	src_init;
	size_t	i;
	size_t	j;

	dst_init = ft_strlen(dst);
	src_init = ft_strlen(src);
	i = dst_init;
	j = 0;
	if (dstsize <= dst_init)
		return (src_init + dstsize);
	while (j < dstsize - dst_init - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_init + dst_init);
}
